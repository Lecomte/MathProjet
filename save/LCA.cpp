#include "LCA.h"

LCA::LCA()
{
	this->nextLink_ = nullptr;
	this->isInstanciate = false;
}

LCA::LCA(float yMax, float x, float coeffDirecteur)
{
	this->yMax_ = yMax;
	this->x_ = x;
	this->inverseCoeffDirecteur_ = 1 / coeffDirecteur;
	this->nextLink_ = nullptr;
	this->isInstanciate = true;
}

LCA::LCA(float yMax, float x, float coeffDirecteur, LCA *nextLink)
{
	this->yMax_ = yMax;
	this->x_ = x;
	this->inverseCoeffDirecteur_ = 1 / coeffDirecteur;
	this->nextLink_ = nextLink;
	this->isInstanciate = true;
}

LCA::LCA(LCA *copy)
{
	this->yMax_ = copy->yMax_;
	this->x_ = copy->x_;
	this->inverseCoeffDirecteur_ = copy->inverseCoeffDirecteur_;
	this->nextLink_ = copy->nextLink_;
	this->isInstanciate = true;
}

void LCA::setNextLink(LCA *nextLink)
{
	this->nextLink_ = nextLink;
}

LCA* LCA::chainLink(LCA *link)
{
	if (this->nextLink_)
		link = this->nextLink_->chainLink(link);
	if (this->inverseCoeffDirecteur_ > link->inverseCoeffDirecteur_)
	{
		this->setNextLink(link);
		return this;
	}
	else{
		link->setNextLink(this);
		return link;
	}
}

void LCA::erase()
{
	*this = this->nextLink_;
}

float LCA::getYMax()
{
	return this->yMax_;
}

float LCA::getInverseCoeffDirecteur()
{
	return this->inverseCoeffDirecteur_;
}

LCA* LCA::getNextLink()
{
	return this->nextLink_;
}

bool LCA::getIsInstanciate()
{
	return this->isInstanciate;
}

LCA::~LCA()
{
}
