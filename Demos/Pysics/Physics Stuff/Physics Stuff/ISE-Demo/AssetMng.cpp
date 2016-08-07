#include "AssetMng.h"


AssetMng::AssetMng(void)
{
}


AssetMng::~AssetMng(void)
{
}

void AssetMng::Load(AS_TYPE type,std::string location)
{
	int loc = strToInt(location);
	if (type == AS_OBJ)
	{
		//if(object.find(location) == object.end())
		if(!object.count(loc))
		{
			//std::cout << "Run" << std::endl;
			object[loc]=objLoader::load(location);
		}
		else
		{
			//std::cout << "Object Already exists in Asset manager" << std::endl;
		}
	}
	else if(type == AS_TEXTURE)
	{
		if(!texture.count(loc))
		{
			//check out this section i'm not sure if it get destroyed if i don't new
			//std::cout << "Run Texture" << std::endl;
			Texture *temp = new Texture();
			temp->load(location);
			temp->setrepeatable(true);
			texture[loc]=temp;
		}
		else
		{
			//std::cout << "Texture Already Exists" << std::endl;
		}
	}
	else if(type == AS_SOUND)
	{
		if(!sounds.count(loc))
		{
			Sound temp;
			temp.Load(location);
			sounds[loc]=temp;
		}
		else
		{
			std::cout<<"Sound File already exists" << std::endl;
		}
	}
	else
	{
		std::cout<<"Error with the type specified" << std::endl;
	}
}

void AssetMng::getData(std::string location, VAO &data)
{
		int loc = strToInt(location);
		if (object.count(loc))//if found
		{
			data = object[loc];
			//return (object[location]);
		}
		else
		{
			
			err.error = "Object could not be found please try again";
			//return (err);
		}

	/*
	else if (type == AS_TEXTURE)
	{
		if
	}
	else
	{
		Error err;
		err.error = "Enum Type specified not correct";
		//return (err);
	}*/
	
}

/*
void AssetMng::getData(std::string location, Texture &text)
{
	if(texture.count(location))
	{
		text = texture[location];
	}
	else
	{
		err.error = "Error: Texture does not exist" ;
	}
}*/

void AssetMng::getData(std::string location)
{
	int loc = strToInt(location);
	if(texture.count(loc))
	{
		texture[loc]->bind();
	}
}

Sound* AssetMng::getData(std::string location, AS_TYPE type)
{
	int loc = strToInt(location);
	if(sounds.count(loc))
	{
		return(&sounds[loc]);
	}
	else
	{
		Sound Err;
		return (&Err);
	}
}

