#include "AMateria.hpp"

AMateria::AMateria(std::string const &_type) : type(_type) {}

std::string const &AMateria::getType() const { return type; };

void AMateria::use(ICharacter &target) { (void)target; };

AMateria::~AMateria() {};