#include "LCA.h"

LCA::LCA()
{
	this->yMax_ = 0.;
	this->x_ = 0.;
	this->inverseCoeffDirecteur_ = 0.;
	//this->nextLink_ = nullptr;
	//this->isInstanciate = false;
}

LCA::LCA(float yMax, float x, float coeffDirecteur)
{
	this->yMax_ = yMax;
	this->x_ = x;
	this->inverseCoeffDirecteur_ = coeffDirecteur;
	//this->nextLink_ = nullptr;
	//this->isInstanciate = true;
}

/*LCA::LCA(float yMax, float x, float coeffDirecteur, LCA *nextLink)
{
	this->yMax_ = yMax;
	this->x_ = x;
	this->inverseCoeffDirecteur_ = coeffDirecteur;
	//this->nextLink_ = nextLink;
	//this->isInstanciate = true;
}*/

LCA::LCA(LCA *copy)
{
	this->yMax_ = copy->yMax_;
	this->x_ = copy->x_;
	this->inverseCoeffDirecteur_ = copy->inverseCoeffDirecteur_;
	//this->nextLink_ = copy->nextLink_;
	//this->isInstanciate = true;
}

float LCA::getXMin()
{
	return this->x_;
}

void LCA::setXMin(float x)
{
	this->x_ = x;
}

LCA& LCA::operator=(const LCA &lca)
{
	this->yMax_ = lca.yMax_;
	this->x_ = lca.x_;
	this->inverseCoeffDirecteur_ = lca.inverseCoeffDirecteur_;
	return *this;
}

int LCA::operator==(const LCA &lca) const
{
	if (this->yMax_ != lca.yMax_) return 0;
	if (this->x_ != lca.x_) return 0;
	if (this->inverseCoeffDirecteur_ != lca.inverseCoeffDirecteur_) return 0;
	return 1;
}
/* This function will be useful for sort the list */
int LCA::operator<(const LCA &lca) const
{
	if (this->x_ == lca.x_ && this->inverseCoeffDirecteur_ < lca.inverseCoeffDirecteur_) return 1;           //if Xmin or the same we sort by cDir
	if (this->x_ < lca.x_) return 1;                                    //by default we sort by Xmin
	return 0;
}

/*void LCA::setNextLink(LCA *nextLink)
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
}*/

float LCA::getYMax()
{
	return this->yMax_;
}

float LCA::getInverseCoeffDirecteur()
{
	return this->inverseCoeffDirecteur_;
}

/*LCA* LCA::getNextLink()
{
	return this->nextLink_;
}

bool LCA::getIsInstanciate()
{
	return this->isInstanciate;
}*/

LCA::~LCA()
{
}
