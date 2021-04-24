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

	void setNewHead(Tree* obj) { // Метод переопределения головного объекта
		head = obj;
	}

	void* getHead() { // Метод получения указателя на головной объект
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

class App : public Tree {
private:
	list<Tree> obj;
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
				} else if (classNumb == 3) {
					obj.push_back(Useless_3(this, tempName2, statusObj)); // Создание
				} else if (classNumb == 4) {
					obj.push_back(Useless_4(this, tempName2, statusObj)); // Создание
				}
				this->ptr.push_back(&obj.back()); // Внесение в список родителя
			}
			else for (list<Tree>::iterator treeObj = obj.begin(); treeObj != obj.end(); treeObj++) { // Дочерний объект для указанного объекта
				if (tempName == treeObj->getName()) { // Поиск имени в качестве родителя
					if (classNumb == 2) {
						obj.push_back(Useless_2(&*treeObj, tempName2, statusObj)); // Создание
					} else if (classNumb == 3) {
						obj.push_back(Useless_3(&*treeObj, tempName2, statusObj)); // Создание
					} else if (classNumb == 4) {
						obj.push_back(Useless_4(&*treeObj, tempName2, statusObj)); // Создание
					}
					treeObj->ptr.push_back(&obj.back()); // Внесение в список родителя
				}
			}
		}
		list<Tree>::iterator treeObj = obj.begin();
		cout << this->ptr.size();
	}

	void test1() {
		for (list<Tree>::iterator treeObj = obj.begin(); treeObj != obj.end(); treeObj++) {
			cout << " " << treeObj->getName();
		}
	}

	void output(list<Tree*> treeO) {
		//if (!treeObj.empty()) cout << "empty"; return;
		for (list<Tree*>::iterator treeObj = treeO.begin(); treeObj != treeO.end(); treeObj++) {
			cout << "The object " << (*treeObj)->getName();
			if ((*treeObj)->getStatus() > 0) cout << " is ready\n";
			else if ((*treeObj)->getStatus() == 0) cout << " is disabled\n";
			else cout << " is not ready\n";
			output((*treeObj)->ptr);
			//cout << &treeObj->ptr;
		}
	}

	int exec_app() {
		/*cout << this->getName() << endl << this->getName();
		for (Tree treeObj : obj) {
			if (treeObj.getHead() == this) cout << "  " << treeObj.getName();
		}
		this->output(obj);
		cout << "\n\n";
		test1();*/
		cout << "The object " << this->getName();
		if (this->getStatus() > 0) cout << " is ready\n";
		else if (this->getStatus() == 0) cout << " is disabled\n";
		else cout << " is not ready\n";
		output(this->ptr);
		return 0;
	}
};

int main() {
	App rootObj(nullptr);
	rootObj.bild_tree_objects(); // Построение дерева объектов
	return rootObj.exec_app(); // Запуск системы
}
