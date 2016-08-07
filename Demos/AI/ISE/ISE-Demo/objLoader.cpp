#include "objLoader.h"


objLoader::objLoader(void)
{
}


objLoader::~objLoader(void)
{
}

VAO objLoader::load(std::string location)
{
	VAO data;

	Assimp::Importer import;
	const aiScene *scene = import.ReadFile(location,aiProcessPreset_TargetRealtime_Fast);

	if(!scene)
	{
		std::cout << "Failed to load file: " << location << std::endl;
		
	}
	else
	{
		aiMesh *mesh = scene->mMeshes[0];

		data.numVerts = mesh->mNumFaces*3;
		
		data.vertexArray = new float[mesh->mNumFaces*3*3];
		data.normalArray = new float[mesh->mNumFaces*3*3];
		data.uvArray = new float[mesh->mNumFaces*3*2];

		for(unsigned int i=0; i<mesh->mNumFaces;i++)
		{
			const aiFace &face = mesh->mFaces[i];

			for(int j=0;j<3;j++)
			{
				aiVector3D uv = mesh->mTextureCoords[0][face.mIndices[j]];
				memcpy(data.uvArray,&uv,sizeof(float)*2);
				data.uvArray+=2;

				aiVector3D normal = mesh->mNormals[face.mIndices[j]];
				memcpy(data.normalArray,&normal,sizeof(float)*3);
				data.normalArray+=3;

				aiVector3D pos = mesh->mVertices[face.mIndices[j]];
				memcpy(data.vertexArray,&pos,sizeof(float)*3);
				data.vertexArray+=3;

			}
		}

		data.uvArray-=mesh->mNumFaces*3*2;
		data.normalArray-=mesh->mNumFaces*3*3;
		data.vertexArray-=mesh->mNumFaces*3*3;

	}

	return(data);
}
