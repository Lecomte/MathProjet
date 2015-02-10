#pragma once

class LCA
{
public:
	LCA();
	LCA(float yMax, float x, float coeffDirecteur);
	LCA(float yMax, float x, float coeffDirecteur, LCA *nextLink);
	LCA(LCA *copy);
	void setNextLink(LCA *nextLink);
	LCA* chainLink(LCA *link);
	void erase();
	float getInverseCoeffDirecteur();
	float getYMax();
	LCA* getNextLink();
	bool getIsInstanciate();
	~LCA();
private:
	float yMax_;
	float x_;
	float inverseCoeffDirecteur_;
	bool isInstanciate;
	LCA *nextLink_;
};