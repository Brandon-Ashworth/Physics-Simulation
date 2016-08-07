#pragma once

#include "Loaderab.h"
#include "VAO.h"
#include <string>

//all the assimp things
#include <assimp\Importer.hpp>
#include <assimp\postprocess.h>
#include <assimp\ai_assert.h>
#include <assimp\mesh.h>
#include <assimp\scene.h>


//use only for testing, remove once finished.
#include <iostream>

/**
 * @brief A Loader function that converts the model data into the common VAO format.
 * 
 * @return VAO, containing the model data needed to be drawn in opengl
 * @author Umar Badat
 * @note I would like to expand the data loaded in to allow it to get more information about the models
 */
class objLoader 
{
public:
	objLoader(void);
	~objLoader(void);

	/**
	 * @brief load data from model
	 * @details Loads data from a range of model formats and coverts them to VAO's so the render engine only needs to handle one type
	 * 
	 * @param location The name and location of the file you want to load in.
	 * @return VAO, containing all the data.
	 */
	static VAO load(std::string location);
};

