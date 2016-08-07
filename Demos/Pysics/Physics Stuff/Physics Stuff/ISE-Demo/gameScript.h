
#pragma once

//#define LUABIND_DYNAMIC_LINK

#include <iostream>
#include <lua.hpp>
#include <luabind/luabind.hpp>
#include <vector>
#include "GameObjectFactory.h"

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
class gameScript
{
public:
	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	gameScript();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	~gameScript();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param s [description]
	 */
	void load(std::string s);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 */
	void setGameObjectModel(std::string m);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param t [description]
	 */
	void setGameObjectTexture(std::string t);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	std::string getGameObjectModel();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	std::string getGameObjectTexture();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param e [description]
	 */
	void setEnable(bool e);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	bool getEnable();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param e [description]
	 */
	void setEnableModelOverride(bool e);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	bool getEnableModelOverride();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param e [description]
	 */
	void setEnableTextureOverride(bool e);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	bool getEnableTextureOverride();

private:
	lua_State* m_LUA;
	std::string m_model;
	std::string m_texture;
	bool m_enabled;
	bool m_modelOverride;
	bool m_textureOverride;
};