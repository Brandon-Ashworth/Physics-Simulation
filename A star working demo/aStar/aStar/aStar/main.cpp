#include <iostream>
#include "as_node.h"
#include "NavMesh.h"

int main()
{
	int size = 4;
	NavMesh mesh;

	mesh.setNavSize(size);
	mesh.initMesh();

	as_node *goal;
	as_node *start;
	goal = mesh.getNode(3,2);
	start = mesh.getNode(1,1);

	mesh.blockNode(2,1);
	mesh.blockNode(2,2);

	//mesh.initMesh();

	std::stack<Vector2Int> ret = mesh.getPath(start,goal);

	//check heuristics is corrent
	as_node *check;
	for(int i=0;i<size;++i)
	{
		for(int j = 0; j<size;++j)
		{
			check = mesh.getNode(i,j);
			std::cout <<"["<<check->getGridX()<<","<<check->getGridY()<<" = "
				<<check->getHueristic()<<"] ";
		}
		std::cout << std::endl;
	}
	
	std::cout <<"Best Path\n"<<std::endl;
	while(!ret.empty())
	{
		std::cout<< ret.top().m_x
			<< ", " << ret.top().m_y <<std::endl;
		ret.pop();
		
	}



	//getchar();
	mesh.initMesh();
	goal = mesh.getNode(0,0);
	start = mesh.getNode(3,2);
	mesh.blockNode(2,1);
	mesh.blockNode(2,2);
	std::stack<Vector2Int> ret2 = mesh.getPath(start,goal);

	//

	
	for(int i=0;i<size;++i)
	{
		for(int j = 0; j<size;++j)
		{
			check = mesh.getNode(i,j);
			std::cout <<"["<<check->getGridX()<<","<<check->getGridY()<<" = "
				<<check->getHueristic()<<"] ";
		}
		std::cout << std::endl;
	}

	std::cout <<"Best Path\n"<<std::endl;
	while(!ret2.empty())
	{
		std::cout<< ret2.top().m_x
			<< ", " << ret2.top().m_y <<std::endl;
		ret2.pop();
		
	}


	getchar();
	return(0);
}