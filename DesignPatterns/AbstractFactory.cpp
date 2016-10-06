#if 0
#include <iostream>

/* Abstract Product */
class DevGroup
{
public:
	virtual void featureGroup() = 0;
};

/* Concrete Product 1 */
class CoderCustom :public DevGroup
{
public:
	void featureGroup()
	{
		std::cout << " Falls under Coder Customization" << std::endl;
	}
};

/* Concrete Product 2 */
class CodeEfficieny : public DevGroup
{
public:
	void featureGroup()
	{
		std::cout << " Falls under Code Efficiency" << std::endl;
	}
};

/* Concrete Product 3 */
class CodeInfra : public DevGroup
{
public:
	void featureGroup()
	{
		std::cout << " Falls under Code Infrastructure" << std::endl;
	}
};

/* Abstract Factory */
class Feature {
public:
	virtual DevGroup *returnGrp() = 0;
};

/* Concrete Factory 1*/
class CoderDataGrp : public Feature
{
public:
	DevGroup *returnGrp()
	{
		return new CoderCustom;
	}
};

/* Concrete Factory 2*/
class ReuasableSubsys : public Feature
{
public:
	DevGroup *returnGrp()
	{
		return new CodeEfficieny;
	}
};

/* Concrete Factory 3*/
class RowMajor : public Feature
{
public:
	DevGroup *returnGrp()
	{
		return new CodeInfra;
	}
};

/* Client (not aware of concrete products) */
class EcoderQE
{
private:
	Feature *featobj;
public:
	EcoderQE(Feature *f)
	{
		featobj = f;
	}

	void returnGrp()
	{
		DevGroup *grp = featobj->returnGrp();
		grp->featureGroup();
	}
};

int main()
{
	Feature *factoryobj = new RowMajor();
	EcoderQE *featmapping = new EcoderQE(factoryobj);
	featmapping->returnGrp();
	return 0;
}
#endif // 0