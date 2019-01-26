#include "SceneGraph.hpp"

//Scene-------------------------------------------------------

Scene::Scene(){}

Scene::Scene(int width,int height):gameRenderer(width,height){}

Scene::~Scene()
{
	for (auto i = Layers.begin(); i != Layers.end(); i++)
		delete *i;
}

void Scene::addLayer(Layer* layer)
{
	Layers.push_back(layer);
}

void Scene::removeLayer(string id)
{
	for (auto i = Layers.begin(); i != Layers.end(); i++)
		if ((*i)->id == id)
		{
			Layers.erase(i);
			break;
		}
}

Layer* Scene::getLayer(string id)
{
	for (auto i = Layers.begin(); i != Layers.end(); i++)
		if ((*i)->id == id)
			return *i;
}

void Scene::render()
{
	for (auto i = Layers.begin(); i != Layers.end(); i++)
		(*i)->render(this);
}

//Layer-----------------------------------------------------

Layer::Layer(string id)
{
	this->id = id;
}

Layer::~Layer()
{
	for (auto i = Nodes.begin(); i != Nodes.end(); i++)
	{
		delete *i;
	}
}

void Layer::addNode(Node* node)
{
	Nodes.push_back(node);
}

void Layer::removeNode(string id)
{
	for (auto i = Nodes.begin(); i != Nodes.end(); i++)
	{
		if ((*i)->id == id)
		{
			Nodes.erase(i);
			break;
		}
	}
}

Node* Layer::getNode(string id)
{
	for (auto i = Nodes.begin(); i != Nodes.end(); i++)
		if ((*i)->id == id)
			return *i;
}

void Layer::render(Scene* scene)
{
	for (auto i = Nodes.begin(); i != Nodes.end(); i++)
		(*i)->render(scene);
}

//Node------------------------------------------------------------

Node::Node(string id)
{
	this->id = id;
}

Node::~Node()
{
}