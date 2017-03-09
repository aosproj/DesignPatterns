#if 0
#include <iostream>

/* Abstract Product */
class Feature
{
public:
	virtual void featureFlag() = 0;
};

/* Concrete Product 1 */
class RowMajor :public Feature
{
public:
	void featureFlag()
	{
		std::cout << "slfeature('RowMajorDimensionSupport',1)" << std::endl;
	}
};

/* Concrete Product 2 */
class ReuableSubsys : public Feature
{
public:
	void featureFlag()
	{
		std::cout << "slfeature('ReusableSubsys',1)" << std::endl;
	}
};

/* Concrete Product 3 */
class CoderDataGrp : public Feature
{
public:
	void featureFlag()
	{
		std::cout << "slfeature('CoderDataGrp',1)" << std::endl;
	}
};

/* Abstract Factory */
class DevGrp {
public:
	virtual Feature *returnFeatFlag() = 0;
};

/* Concrete Factory 1*/
class CodeInfra : public DevGrp
{
public:
	Feature *returnFeatFlag()
	{
		return new RowMajor;
	}
};

/* Concrete Factory 2*/
class CoderCustom : public DevGrp
{
public:
	Feature *returnFeatFlag()
	{
		return new CoderDataGrp;
	}
};

/* Concrete Factory 3*/
class CodeEfficieny : public DevGrp
{
public:
	Feature *returnFeatFlag()
	{
		return new ReuableSubsys;
	}
};

/* Client (not aware of concrete products) */
class EcoderQE
{
private:
	DevGrp *devobj;
public:
	EcoderQE(DevGrp *d)
	{
		devobj = d;
	}

	void returnFeatFlag()
	{
		Feature *feat = devobj->returnFeatFlag();
		feat->featureFlag();
	}
};

int main()
{
	DevGrp *factoryobj = new CodeInfra();
	EcoderQE *featmapping = new EcoderQE(factoryobj);
	featmapping->returnFeatFlag();

	factoryobj = new CoderCustom();
	featmapping = new EcoderQE(factoryobj);
	featmapping->returnFeatFlag();

	factoryobj = new CodeEfficieny();
	featmapping = new EcoderQE(factoryobj);
	featmapping->returnFeatFlag();
	return 0;
}
#endif // 0
