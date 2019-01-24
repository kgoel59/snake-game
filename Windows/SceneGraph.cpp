#include "SceneGraph.hpp"

//Scene-------------------------------------------------------

Scene::~Scene()
{
	for (auto i = Layers.begin(); i != Layers.end(); i++)
		delete *i;
}

void Scene::addLayer(Layer* layer)
{
	Layers.push_back(layer);
}

void Scene::deleteLayer(string id)
{
	for (auto i = Layers.begin(); i != Layers.end(); i++)
		if ((*i)->id == id)
		{
			delete *i;
			Layers.erase(i);
		}
}

void Scene::render()
{
	for (auto i = Layers.begin(); i != Layers.end(); i++)
		(*i)->render();
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

void Layer::deleteNode(string id)
{
	for (auto i = Nodes.begin(); i != Nodes.end(); i++)
		if ((*i)->id == id)
		{
			delete *i;
			Nodes.erase(i);
		}
}

void Layer::render()
{
	for (auto i = Nodes.begin(); i != Nodes.end(); i++)
		(*i)->render();
}

//Node------------------------------------------------------------

Node::Node(string id)
{
	this->id = id;
}

Node::~Node()
{
}