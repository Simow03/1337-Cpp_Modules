#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < size; i++)
        templates[i] = NULL;
};

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < size; i++)
    {
        if (other.templates[i])
            templates[i] = other.templates[i]->clone();
        else
            templates[i] = NULL;
    }
};

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{

    if (this != &other)
    {
        for (int i = 0; i < size; i++)
            delete templates[i];

        for (int i = 0; i < size; i++)
        {
            if (other.templates[i])
                this->templates[i] = other.templates[i]->clone();
            else
                this->templates[i] = NULL;
        }
    }

    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < size; i++)
        delete templates[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return;

    for (int i = 0; i < size; i++)
    {
        if (!templates[i])
        {
            templates[i] = m->clone();
            delete m;
            return;
        }
    }
    delete m;
};

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < size; i++)
        if (templates[i] && templates[i]->getType() == type)
            return templates[i]->clone();
    return NULL;
};