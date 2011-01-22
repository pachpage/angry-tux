#ifndef MAP_H
#define MAP_H
#include <tinyxml.h>
#include "../Utilities/Config.h"
#include "../Entities/EntityManager.h"

class Map
{
    public:
        Map(std::string &file);
        virtual ~Map();
        void load();
        std::string getName() const;
        std::string getAuthor() const;
        std::string getDate() const;
        std::string getVersion() const;
        sf::Vector2i getCamPosition() const;
    protected:
    private:
        std::string _name
                    ,_author
                    ,_date
                    ,_version
                    ,_file;
        sf::Vector2i _camposition;
};

#endif // MAP_H
