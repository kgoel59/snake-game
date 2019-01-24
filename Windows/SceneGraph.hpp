#pragma once


#include <vector>
#include <string>

using std::vector;
using std::string;

class Scene;
class Layer;
class Node;

class Scene
{
	vector<Layer*> Layers;

public:

	~Scene();

	void addLayer(Layer* layer);
	void deleteLayer(string id);
	void render();
};

class Layer
{
	vector<Node*> Nodes;

public:

	string id;

	Layer(string);
	~Layer();

	void addNode(Node* node);
	void deleteNode(string id);
	void render();
};

class Node
{
public:

	string id;

	Node(string);
	virtual ~Node();

	virtual void render() = 0;
};