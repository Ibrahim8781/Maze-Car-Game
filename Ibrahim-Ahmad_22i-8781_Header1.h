//Mohammad_Ibraheem_22I-2603, Ibrahim_Ahmed_22I-8781
#pragma once
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<list>
#include<queue>
#include<chrono>
using namespace std;
using namespace std::chrono;
class MapVertex {
private:
    int ver;
    char type;
    bool visited;
    MapVertex* weightEdge[4];
    double weightEdgeAm[4];
    list<MapVertex*> adjLst;
public:
    MapVertex() {
        ver = 0;
        type = '.';
        adjLst = list<MapVertex*>();
    }
    MapVertex(int ver) {
        this->ver = ver;
    }
    MapVertex(int ver, char type) {
        this->ver = ver;
        this->type = type;
    }
    int getVer() {
        return ver;
    }
    char getType() {
        return type;
    }
    void setVer(int ver) {
        this->ver = ver;
    }
    void setType(char type) {
        this->type = type;
    }
    void setVisit(bool visited) {
        this->visited = visited;
    }
    bool getVisit() {
        return visited;
    }
    const list<MapVertex*>& getAdjLst() {
        return adjLst;
    }
    void addAdjLst(MapVertex* vertex) {
        adjLst.push_back(vertex);
    }
};
class Map {
private:
    MapVertex* vertices[36];
    int width;
    int height;
    queue<MapVertex*> obstacles;
    queue<MapVertex*> powerups;
    int score;
public:
    Map() {
        for (int i = 0; i < 36; i++) {
            vertices[i] = new MapVertex(i + 1, '*');
        }
        width = 6;
        height = 6;
    }
    void makePaths() {
        for (int i = 0; i < 36; i++) {
            if (i + 6 < 36 && vertices[i + 6] != NULL) {
                addPath(i, i + 6);
            }
            else if (i - 6 >= 0 && vertices[i - 6] != NULL) {
                addPath(i, i - 6);
            }
            if ((i + 1) % 6 != 0 && vertices[i + 1] != NULL) {
                addPath(i, i + 1);
            }
            else if (i % 6 != 0 && vertices[i - 1] != NULL) {
                addPath(i, i - 1);
            }
        }
    }
    void showConn() {
        for (int i = 0; i < 36; i++) {
            cout << "Vertex " << i + 1 << " Adjacent List: ";
            for (list<MapVertex*>::const_iterator it = vertices[i]->getAdjLst().begin(); it != vertices[i]->getAdjLst().end(); ++it) {
                cout << (*(it))->getVer() << " ";
            }
            cout << endl;
        }
    }
    void Hard() {
        int arr[36];
        for (int i = 0; i < 36; i++) {
            vertices[i]->setVer(i);
        }
        vertices[0]->setType('S');
        vertices[35]->setType('E');
        for (int i = 0; i < 36; i++) {
        START:
            bool flag = false;
            int randVer = rand() % 36;
            for (int h = 0; h < 36; h++) {
                if (arr[h] == randVer) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                goto START;
            }
            arr[i] = randVer;
            if (vertices[randVer]->getType() != 'S' && vertices[randVer]->getType() != 'E') {
                if (i <= 5 && i != 0) {
                    vertices[randVer]->setType('$');
                }
                if (i > 5 && i <= 25) {
                    vertices[randVer]->setType('*');
                }
                if (i > 25) {
                    vertices[randVer]->setType('#');
                }
            }
        }
    }
    void displayMap() {
        srand(time(NULL));
        makePaths();
        cout << "\n\n\n\n\n";
        for (int i = 0; i < height; i++) {
            cout << "\t\t\t\t\t";
            for (int j = 0; j < width; j++) {
                int index = i * width + j;
                if (j != 0) {
                    if (j == width - 1) {
                        if (checkAdjLst(index, index - 1)) {
                            cout << "  ---  ";
                        }
                    }
                    if (checkAdjLst(index, index + 1)) {
                        cout << "  ---  ";
                    }
                    else if (j != width - 1) {
                        cout << "     ";
                    }
                }
                /*if (vertices[index]->getType()) {
                    cout << RED<<vertices[index]->getType()<<GREEN;
                }
                else {*/
                cout << vertices[index]->getType();
                //}
            }
            cout << endl << endl;
            cout << "\t\t\t\t\t";
            for (int k = 0; k < width; k++) {
                int index = i * width + k;
                if (checkAdjLst(index, index + 6)) {
                    cout << "|";
                }
                cout << "       ";
            }
            if (i != height - 1) {
                cout << endl << endl;
            }
        }
    }
    void Easy() {
        int arr[36];
        for (int i = 0; i < 36; i++) {
            vertices[i]->setVer(i);
        }
        vertices[0]->setType('S');
        vertices[35]->setType('E');
        for (int i = 0; i < 36; i++) {
        START:
            bool flag = false;
            int randVer = rand() % 36;
            for (int h = 0; h < 36; h++) {
                if (arr[h] == randVer) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                goto START;
            }
            arr[i] = randVer;
            if (vertices[randVer]->getType() != 'S' && vertices[randVer]->getType() != 'E') {
                if (i <= 15 && i != 0) {
                    vertices[randVer]->setType('$');
                }
                if (i > 15 && i <= 30) {
                    vertices[randVer]->setType('*');
                }
                if (i > 30) {
                    vertices[randVer]->setType('#');
                }
            }
        }
    }
    void Normal() {
        int arr[36];
        for (int i = 0; i < 36; i++) {
            vertices[i]->setVer(i);
        }
        vertices[0]->setType('S');
        vertices[35]->setType('E');
        for (int i = 0; i < 36; i++) {
        START:
            bool flag = false;
            int randVer = rand() % 36;
            for (int h = 0; h < 36; h++) {
                if (arr[h] == randVer) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                goto START;
            }
            arr[i] = randVer;
            if (vertices[randVer]->getType() != 'S' && vertices[randVer]->getType() != 'E') {
                if (i <= 10 && i != 0) {
                    vertices[randVer]->setType('$');
                }
                if (i > 10 && i <= 26) {
                    vertices[randVer]->setType('*');
                }
                if (i > 26) {
                    vertices[randVer]->setType('#');
                }
            }
        }
    }
    auto manGame(int lvl) {
        if (lvl == 1) {
            Easy();
        }
        else if (lvl == 2) {
            Normal();
        }
        else if (lvl == 3) {
            Hard();
        }
        char ch, play;
        MapVertex* curr = new MapVertex(0, 'P');
        MapVertex* temp = vertices[0];
        int n = 0;
        char as[4];
        bool flag = false;
        auto beg = high_resolution_clock::now();
        do {
            system("cls");
            cout << "Your Score: " << score << endl;
            cout << "\nHighest Score: ";
            showHigh();
            displayMap();
            if (curr->getVer() == 35) {
                score -= 10;
                system("cls");
                cout << "\n\t\t\t\t\tCongratulations! You reached the end goal. Game over." << endl;
                break;
            }
            ch = _getch();
            int currPos = curr->getVer();
            if (n != 0) {
                if (flag) {
                    vertices[temp->getVer()]->setType('*');
                    vertices[temp->getVer()]->setVisit(true);
                }
                else {
                    vertices[temp->getVer()]->setType(play);
                    vertices[temp->getVer()]->setVisit(true);
                }
            }
            if (n == 0) {
                if (flag) {
                    vertices[temp->getVer()]->setType('*');
                    vertices[temp->getVer()]->setVisit(true);
                }
                else {
                    vertices[temp->getVer()]->setType(temp->getType());
                    vertices[temp->getVer()]->setVisit(true);
                }
            }
            switch (ch) {
            case 72: { // Up arrow key
                if (currPos >= 6) {
                    curr->setVer(currPos - 6);
                    score += 10;
                }
                break;
            }
            case 80: { // Down arrow key
                if (currPos < 30) {
                    curr->setVer(currPos + 6);
                    score += 10;
                }
                break;
            }
            case 75: {// Left arrow key
                if (currPos % 6 != 0) {
                    curr->setVer(currPos - 1);
                    score += 10;
                }
                break;
            }
            case 77: {// Right arrow key
                if ((currPos + 1) % 6 != 0) {
                    curr->setVer(currPos + 1);
                    score += 10;
                }
                break;
            }
            }
            play = vertices[curr->getVer()]->getType();
            temp = vertices[curr->getVer()];
            flag = checkFood(temp);
            if (temp->getType() == '#') {
                if (!temp->getVisit()) {
                    obstacles.push(temp);
                }
                score -= 10;
                score = score / 2;
            }
            if (temp->getType() == '$') {
                score -= 10;
                if (!temp->getVisit()) {
                    powerups.push(temp);
                }
                if (score >= 0) {
                    score = score + 100;
                }
                else {
                    score = score - score;
                }
            }

            temp->setType('P');
            n++;
        } while (1);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(end - beg);
        return duration;
    }
    void addPath(int v1, int v2) {
        MapVertex* temp = new MapVertex(v2 + 1);
        vertices[v1]->addAdjLst(temp);
        temp = new MapVertex(v1 + 1);
        vertices[v2]->addAdjLst(temp);
    }
    bool checkAdjLst(int v1, int v2) {
        for (list<MapVertex*>::const_iterator it = vertices[v1]->getAdjLst().begin(); it != vertices[v1]->getAdjLst().end(); ++it) {
            if ((*(it))->getVer() == v2 + 1) {
                return true;
            }
        }
        return false;
    }
    bool checkFood(MapVertex* ver) {
        if (ver->getType() == '$') {
            return true;
        }
        return false;
    }
    int getTotalObs() {
        int count = 0;
        while (!obstacles.empty()) {
            delete obstacles.front();
            obstacles.pop();
            count++;
        }
        return count;
    }
    int getScore() {
        return score;
    }
    void showHigh() {
        ifstream recFile("Record.txt");
        string ss;
        list<string> nArr;
        list<int> sArr;
        int count = 1;
        int skipCount = 0;
        while (recFile >> ss) {
            if (count == 1) {
                nArr.push_front(ss);
                skipCount = 0;
            }
            if (count % 3 == 0) {
                sArr.push_front(stoi(ss));
                skipCount = 2;
            }
            else if (skipCount == 2) {
                nArr.push_back(ss);
                skipCount = 0;
            }
            count++;
        }
        int max = 0;
        int sCount = 0;
        for (list<int>::iterator it = sArr.begin(); it != sArr.end(); ++it) {
            if (*(it) > max) {
                max = *it;
            }
            sCount++;
        }
        int sCount2 = 1;
        string name;
        for (list<string>::iterator it = nArr.begin(); it != nArr.end(); ++it) {
            if (sCount == sCount2) {
                name = *it;
                break;
            }
            sCount2++;
        }
        cout << name << " (" << max << ")" <<  endl;
        recFile.close();
    }
    ~Map() {
        for (int i = 0; i < 36; i++) {
            delete vertices[i];
        }
    }
};
class Collectible {
private:
	int value;
	MapVertex* location;
	char type;
public:
	Collectible() {
		value = 0;
		location = NULL;
		type = '\0';
	}
	int getValue() {
		return value;
	}
	MapVertex* getLoc() {
		return location;
	}
	char getType() {
		return type;
	}
	void setValue(int value) {
		this->value = value;
	}
	void setLoc(MapVertex* location) {
		this->location = location;
	}
	void setType(char type) {
		this->type = type;
	}
};