#pragma once

#include "Engine.hpp"

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

	Engine gameRenderer;

	Scene();
	Scene(int width,int height);
	~Scene();

	void addLayer(Layer* layer);
	void removeLayer(string id);
	Layer* getLayer(string id);
	void render();
};

class Layer
{
	vector<Node*> Nodes;

public:

	string id;

	Layer(string id);
	~Layer();

	void addNode(Node* node);
	void removeNode(string id);
	Node* getNode(string id);
	void render(Scene*);
};

class Node
{
public:

	string id;

	Node(string id);
	virtual ~Node();

	virtual void render(Scene*) = 0;
};