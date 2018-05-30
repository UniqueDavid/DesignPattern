#include <iostream>
#include <string>
#include <vector>
using namespace std;

//������ԭ���ֽ�����֪ʶԭ��
class AbstractBuilding{
public:
	virtual void sale() = 0;
public:
	string mQuality;
};

//¥��A
class BuildingA :public AbstractBuilding{
public:
	BuildingA(){
		mQuality = "�ߵ�Ʒ��";
	}
	virtual void sale(){
		cout << "¥��A" <<mQuality << endl;
	}

};

//¥��B
class BuildingB :public AbstractBuilding{
public:
	BuildingB(){
		mQuality = "�͵�Ʒ��";
	}
	virtual void sale(){
		cout << "¥��B" << mQuality << endl;
	}

};

void test01(){
	BuildingA *ba = new BuildingA;
	if (ba->mQuality == "�ߵ�Ʒ��")
		ba->sale();
	BuildingB *bb = new BuildingB;
	if (bb->mQuality == "�ߵ�Ʒ��")
		bb->sale();
}

//�н���
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

	//�����ṩ�ӿ�
	AbstractBuilding* findMyBuilding(string quality){
		for (vector<AbstractBuilding*>::iterator it = buildingVectors.begin(); it != buildingVectors.end(); it++){
			if ((*it)->mQuality == "�ߵ�Ʒ��"){
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
	AbstractBuilding* building = m->findMyBuilding("�ߵ�Ʒ��");
	if (building != NULL)
	{
		building->sale();
	}
	else{
		cout << "û�з���Ҫ���¥��" << endl;
	}
	return 0;
}