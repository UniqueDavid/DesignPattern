#include <iostream>
#include <string>
#include <vector>
using namespace std;

//迪米特原则，又叫最少知识原则
class AbstractBuilding{
public:
	virtual void sale() = 0;
public:
	string mQuality;
};

//楼盘A
class BuildingA :public AbstractBuilding{
public:
	BuildingA(){
		mQuality = "高等品质";
	}
	virtual void sale(){
		cout << "楼盘A" <<mQuality << endl;
	}

};

//楼盘B
class BuildingB :public AbstractBuilding{
public:
	BuildingB(){
		mQuality = "低等品质";
	}
	virtual void sale(){
		cout << "楼盘B" << mQuality << endl;
	}

};

void test01(){
	BuildingA *ba = new BuildingA;
	if (ba->mQuality == "高等品质")
		ba->sale();
	BuildingB *bb = new BuildingB;
	if (bb->mQuality == "高等品质")
		bb->sale();
}

//中介类
class Mediator{
public:
	Mediator(){
		AbstractBuilding* building = new BuildingA;
		buildingVectors.push_back(building);
		building = new BuildingB;
		buildingVectors.push_back(building);
	}
	~Mediator(){
		for (vector<AbstractBuilding*>::iterator it = buildingVectors.begin(); it != buildingVectors.end(); it++){
			if (*it != NULL){
				delete *it;
			}
		}
	}

	//对外提供接口
	AbstractBuilding* findMyBuilding(string quality){
		for (vector<AbstractBuilding*>::iterator it = buildingVectors.begin(); it != buildingVectors.end(); it++){
			if ((*it)->mQuality == "高等品质"){
				return *it;
			}
		}
		return NULL;
	}
public:
	vector<AbstractBuilding*> buildingVectors;

};
int main(int argc, char **argv)
{
	//test01();
	Mediator *m = new Mediator;
	AbstractBuilding* building = m->findMyBuilding("高等品质");
	if (building != NULL)
	{
		building->sale();
	}
	else{
		cout << "没有符合要求的楼盘" << endl;
	}
	return 0;
}