#include "gameScript.h"

gameScript::gameScript()
{
	m_LUA = luaL_newstate();
	m_enabled = false;
	m_modelOverride = false;
	m_textureOverride = false;
	m_model = "";
	m_texture = "";
}

gameScript::~gameScript()
{
}

void gameScript::load(std::string s)
{
	m_LUA = lua_open();

	luaL_openlibs(m_LUA);
	luabind::open(m_LUA);
	
	//luabind::module(m_LUA)
	//[
		/*luabind::class_<GameObject>("GameObject"),
		luabind::class_<Object2D, GameObject>("GameObject2D"),
		luabind::class_<Object3D, GameObject>("GameObject3D"),
		luabind::class_<Effect, GameObject>("GameEffect")
		.def(luabind::constructor<>())
		.def("load", &GameObject::draw)
		.def("translate", &GameObject::translate)
		.def("setPos", &GameObject::setPos)*/
		/*
		luabind::class_<gameScript>("gameScript")
		.def(luabind::constructor<>())
		.def("setGameObjectModel", &gameScript::setGameObjectModel)
		.def("setGameObjectTexture", &gameScript::setGameObjectTexture)
		*/
	//];
	
	const char* tempChar = s.c_str();
	luaL_dofile(m_LUA, tempChar);

	m_model = luabind::call_function<std::string>(m_LUA, "setGameObjectModel");
	m_modelOverride = luabind::call_function<bool>(m_LUA, "enableGameObjectModel");
	m_texture = luabind::call_function<std::string>(m_LUA, "setGameObjectTexture");
	m_textureOverride = luabind::call_function<bool>(m_LUA, "enableGameObjectTexture");

	lua_close(m_LUA);
}

void gameScript::setGameObjectModel(std::string m)
{
	m_model = m;
}

void gameScript::setGameObjectTexture(std::string t)
{
	m_texture = t;
}

std::string gameScript::getGameObjectModel()
{
	return m_model;
}

std::string gameScript::getGameObjectTexture()
{
	return m_texture;
}

void gameScript::setEnable(bool e)
{
	m_enabled = e;
}

bool gameScript::getEnable()
{
	return m_enabled;
}

void gameScript::setEnableModelOverride(bool e)
{
	m_modelOverride = e;
}

bool gameScript::getEnableModelOverride()
{
	return m_modelOverride;
}

void gameScript::setEnableTextureOverride(bool e)
{
	m_textureOverride = e;
}

bool gameScript::getEnableTextureOverride()
{
	return m_textureOverride;
}