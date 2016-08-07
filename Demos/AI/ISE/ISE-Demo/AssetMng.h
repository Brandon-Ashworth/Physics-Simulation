#pragma once

#include <string>
#include <functional>
#include <map>
#include "VAO.h"
#include "objLoader.h"
#include "Texture.h"
#include "Sound.h"
/**
 * @brief This class stores and manages all the assets in the engine
 * @details It takes in all Assets and loads them in, it will then take in the asset and only load it once. when asked for data it will return the same data if the request is the same. 
 * 
 * @author Umar Badat
 * @bug This function does not use the best of design, it could be easier to expand with the use of factories.
 */
class AssetMng
{
public:
	AssetMng(void);
	~AssetMng(void);

	enum AS_TYPE {
		AS_TEXTURE = 0,
		AS_OBJ,
		AS_SOUND
	};

	
	/**
	 * @brief Load in an asset from a file location
	 * @details A file is specified along with its asset type (texture, object or sound)
	 * an AS_TYPE is passed in to specify the type, while the string is for the location.
	 * This class checks to see if it exists to ensure assets are only loaded once.
	 * 
	 * @param E AS_TYPE specifying what kind of data structure is waiting for it
	 * @param location the relative file location, and it is also the name
	 */
	void Load(AS_TYPE,std::string location);

	/**
	 * @brief gets a VAO of the data with that string as its name	
	 * @details Takes in a string of the name and gives back a common data struxture
	 * 
	 * @param location String, This is both the location and the name
	 * @param data VAO, a data structure that we will assign the data to.
	 */ 
	void getData(std::string location,VAO &data);

	/**
	 * @brief Get the texture associated with that file location (name)
	 * 
	 * 
	 * @param location String, both the name and location of the file you want the data from
	 * @param text a place for us to assign the data you want
	 */
	//void getData(std::string location, Texture &text);

	void getData(std::string location);

	Sound* getData(std::string location, AS_TYPE type);

private:
	std::map<int,VAO> object;
	std::map<int,Texture*> texture;
	std::map<int,Sound> sounds;
	Error err;

	std::hash<std::string> strToInt;
	
};

