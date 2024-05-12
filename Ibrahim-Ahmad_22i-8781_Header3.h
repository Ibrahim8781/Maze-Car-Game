//Mohammad_Ibraheem_22I-2603, Ibrahim_Ahmed_22I-8781
#pragma once
#include< iostream>
#include<fstream>
#include<sstream>
#include <queue>
using namespace std;
class Node {
public:
	string name;
	int score;
	Node* left;
	Node* right;
	Node(string name, int t)
	{
		this->name = name;
		this->score = t;
		left = NULL;
		right = NULL;
	}
};
class BST {
	Node* root;
	Node* InsertIntoBST(Node* root, Node* temp)
	{
		if (root == NULL)
		{
			root = temp;
			return root;
		}
		if (temp->score > root->score)
			root->right = InsertIntoBST(root->right, temp);
		else
			root->left = InsertIntoBST(root->left, temp);
		return root;
	}
	void WriteTreeToFile(Node* node, ofstream& outputFile)
	{
		if (node)
		{
			outputFile << node->name << " ~ " << node->score << endl;
			WriteTreeToFile(node->left, outputFile);
			WriteTreeToFile(node->right, outputFile);
		}
	}
public:
	BST()
	{
		root = NULL;
	}
	void Insert(string name, int score)
	{
		Node* temp = new Node(name, score);
		Node* root = this->root;
		InsertIntoBST(root, temp);
	}
	void WriteToFile(const string& filename)
	{
		ofstream outputFile("Record.txt");

		if (!outputFile.is_open())
		{
			cout << "Error: Unable to open file " << filename << " for writing." << endl;
			return;
		}

		WriteTreeToFile(root, outputFile);

		outputFile.close();
		cout << "Tree content has been written to " << filename << " successfully." << endl;
	}
	void LevelOrderTraversal()
	{
		queue<Node*> q;
		q.push(root);
		q.push(NULL);
		while (!q.empty())
		{
			Node* temp = q.front();
			q.pop();
			if (temp == NULL)
			{
				cout << endl;
				if (!q.empty())
				{
					q.push(NULL);
				}
			}
			else
			{
				cout << temp->name << " ~ " << temp->score;
				if (temp->left)
				{
					q.push(temp->left);
				}
				if (temp->right)
				{
					q.push(temp->right);
				}
			}
		}
	}
	void ReadFromFile(const string& filename)
	{
		ifstream inputFile(filename);
		if (!inputFile.is_open())
		{
			cout << "Error: Unable to open file " << filename << " for reading." << endl;
			return;
		}
		string line;
		while (getline(inputFile, line))
		{
			istringstream iss(line);
			string name;
			int score;
			if (!(iss >> name >> score))
			{
				cout << "Error: Invalid data format in the file." << endl;
				break;
			}
			Insert(name, score);
		}
		inputFile.close();
		cout << "Tree content has been read from " << filename << " successfully." << endl;
	}
};