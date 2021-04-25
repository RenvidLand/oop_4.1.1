#include <iostream>
#include <list>
#include <string>
using namespace std;

class Tree {
private:
	Tree* head; // Указатель на головной объект
	string objName; // Наименование объекта
	int statusObj;
public:
	int levelOfInherit = 0;
	list<Tree*> ptr; // Список указателей на объекты подчиненных

	Tree(Tree* m_head = nullptr, string m_objName = "", int tempStatus = 0) { // Параметризированный конструктор
		head = m_head;
		objName = m_objName;
		statusObj = tempStatus;
	}

	void setName(string m_objName) { // Метод определения имени объекта
		objName = m_objName;
	}

	string getName() { // Метод получения имени объекта
		return objName;
	}

	void output(list<Tree> treeObj) { // Метод вывода наименований объектов в дереве
		for (list<Tree>::iterator treeO = treeObj.begin(); treeO != treeObj.end(); treeO++) {
			if (!treeO->ptr.empty()) {
				cout << endl << treeO->getName();
				for (Tree* j : treeO->ptr) {
					cout << "  " << j->getName();
				}
			}
		}
	}

	void* findByName(list<Tree> treeObj, string name) {
		for (list<Tree>::iterator treeO = treeObj.begin(); treeO != treeObj.end(); treeO++) {
			if (treeO->getName() == name) {
				return treeO->getHead();
			}
		}
	}

	void setNewHead(Tree* obj) { // Метод переопределения головного объекта
		head = obj;
	}

	Tree* getHead() { // Метод получения указателя на головной объект
		return head;
	}

	void setStatus(int tempStatus) { // Метод переопределения головного объекта
		statusObj = tempStatus;
	}

	int getStatus() { // Метод переопределения головного объекта
		return statusObj;
	}
};

class Useless_2 : public Tree {
public:
	Useless_2(Tree* m_head, string m_objName, int tempStatus) : Tree(m_head, m_objName, tempStatus) {}
};

class Useless_3 : public Tree {
public:
	Useless_3(Tree* m_head, string m_objName, int tempStatus) : Tree(m_head, m_objName, tempStatus) {}
};

class Useless_4 : public Tree {
public:
	Useless_4(Tree* m_head, string m_objName, int tempStatus) : Tree(m_head, m_objName, tempStatus) {}
};

class Useless_5 : public Tree {
public:
	Useless_5(Tree* m_head, string m_objName, int tempStatus) : Tree(m_head, m_objName, tempStatus) {}
};

class Useless_6 : public Tree {
public:
	Useless_6(Tree* m_head, string m_objName, int tempStatus) : Tree(m_head, m_objName, tempStatus) {}
};

class App : public Tree {
private:
	list<Tree> obj;
	int coutOfObj = 1;
public:
	App(App* app) {
		this->setNewHead(app);
		this->setStatus(1);
	}

	void bild_tree_objects() {
		string tempName, tempName2;
		int classNumb, statusObj;
		cin >> tempName;
		this->setName(tempName);
		while (true) {
			cin >> tempName;
			if (tempName == "endtree") break;
			cin >> tempName2 >> classNumb >> statusObj;
			if (tempName == this->getName()) { // Дочерний объект для root
				if (classNumb == 2) {
					obj.push_back(Useless_2(this, tempName2, statusObj)); // Создание
				}
				else if (classNumb == 3) {
					obj.push_back(Useless_3(this, tempName2, statusObj)); // Создание
				}
				else if (classNumb == 4) {
					obj.push_back(Useless_4(this, tempName2, statusObj)); // Создание
				}
				else if (classNumb == 5) {
					obj.push_back(Useless_5(this, tempName2, statusObj)); // Создание
				}
				else if (classNumb == 6) {
					obj.push_back(Useless_6(this, tempName2, statusObj)); // Создание
				}
				this->ptr.push_back(&obj.back()); // Внесение в список родителя
			}
			else for (list<Tree>::iterator treeObj = obj.begin(); treeObj != obj.end(); treeObj++) { // Дочерний объект для указанного объекта
				if (tempName == treeObj->getName()) { // Поиск имени в качестве родителя
					if (classNumb == 2) {
						obj.push_back(Useless_2(&*treeObj, tempName2, statusObj)); // Создание
					}
					else if (classNumb == 3) {
						obj.push_back(Useless_3(&*treeObj, tempName2, statusObj)); // Создание
					}
					else if (classNumb == 4) {
						obj.push_back(Useless_4(&*treeObj, tempName2, statusObj)); // Создание
					}
					else if (classNumb == 5) {
						obj.push_back(Useless_5(&*treeObj, tempName2, statusObj)); // Создание
					}
					else if (classNumb == 6) {
						obj.push_back(Useless_6(&*treeObj, tempName2, statusObj)); // Создание
					}
					treeObj->ptr.push_back(&obj.back()); // Внесение в список родителя
				}
			}
		}
	}

	void output2(list<Tree*> treeO) {
		for (list<Tree*>::iterator treeObj = treeO.begin(); treeObj != treeO.end(); treeObj++) {
			if (coutOfObj <= obj.size()) cout << "\n";
			cout << "The object " << (*treeObj)->getName();
			if ((*treeObj)->getStatus() > 0) cout << " is ready";
			else if ((*treeObj)->getStatus() == 0) cout << " is disabled";
			else cout << " is not ready";
			coutOfObj++;
			output2((*treeObj)->ptr);
		}
	}

	void findLevelOfInherit(Tree* obj) {
		Tree* tempObj = obj->getHead();
		int tempLOI = tempObj->levelOfInherit;
		obj->levelOfInherit = tempLOI + 1;
	}

	void output3(list<Tree*> treeObj) {
		string gap = "";
		for (list<Tree*>::iterator treeO = treeObj.begin(); treeO != treeObj.end(); treeO++) {
			findLevelOfInherit(*treeO);
			if (coutOfObj <= obj.size()) cout << "\n";
			gap.resize((*treeO)->levelOfInherit, '	');
			cout << gap << (*treeO)->getName();
			coutOfObj++;
			output3((*treeO)->ptr);
		}
	}

	int exec_app() {
		/*string tempName = "object_1";
		this->findByName(obj, tempName);*/

		/*cout << "The object " << this->getName();
		if (this->getStatus() > 0) cout << " is ready";
		else if (this->getStatus() == 0) cout << " is disabled";
		else cout << " is not ready";
		output2(this->ptr);*/

		cout << this->getName();
		output3(this->ptr);

		return 0;
	}
};

int main() {
	App rootObj(nullptr);
	rootObj.bild_tree_objects(); // Построение дерева объектов
	return rootObj.exec_app(); // Запуск системы
}