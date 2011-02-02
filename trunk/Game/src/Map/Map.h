#ifndef MAP_H
#define MAP_H
#include <tinyxml.h>
#include "../Utilities/Config.h"
#include "../Entities/EntityManager.h"

class Map
{
    private:
        int _id;
        std::string _world
                    ,_name
                    ,_author
                    ,_date
                    ,_version
                    ,_file;
        sf::Vector2i _mapSize;

    public:
        Map(std::string &file
            ,int id
            ,std::string world);
        virtual ~Map();
        void load();
        int getId() const;
        std::string& getWorld();
        std::string& getName();
        std::string& getAuthor();
        std::string& getDate();
        std::string& getVersion();
        sf::Vector2i& getMapSize();
};

#endif // MAP_H
