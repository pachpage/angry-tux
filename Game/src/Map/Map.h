#ifndef MAP_H
#define MAP_H
#include <tinyxml.h>
#include "../Utilities/Config.h"
#include "../Entities/EntityManager.h"

class Map
{
    public:
        Map(std::string &file
            ,int id);
        virtual ~Map();
        void load();
        int getId() const;
        std::string getName() const;
        std::string getAuthor() const;
        std::string getDate() const;
        std::string getVersion() const;
        sf::Vector2i getCamPosition() const;
        sf::Vector2i getMapSize() const;
    protected:
    private:
        int _id;
        std::string _name
                    ,_author
                    ,_date
                    ,_version
                    ,_file;
        sf::Vector2i _camposition;
        sf::Vector2i _mapSize;
};

#endif // MAP_H
