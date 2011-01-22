/*
* Class RessourceManager
* Manage ressources creation for better use of memory
* @author : Adrian Gaudebert - adrian.gaudebert@gmail.com
            Nicolas Beaudrot - nicolas.beaudrot@gmail.com
*/

#include "RessourceManager.h"

RessourceManager::RessourceManager(){

}

RessourceManager::~RessourceManager()
{
    //On détruit toutes les images restantes
    std::map<std::string, sf::Image*>::iterator it;
    for(it = Images.begin(); it != Images.end(); it++) {
        delete it->second;
    }

    //On détruit toutes les polices
    std::map<std::string, sf::Font*>::iterator it2;
    for(it2 = Fonts.begin(); it2 != Fonts.end(); it2++) {
        delete it2->second;
    }
    //On détruit tous les son
    std::map<std::string, sf::SoundBuffer*>::iterator it3;
    for(it3 = Sounds.begin(); it3 != Sounds.end(); it3++) {
        delete it3->second;
    }
}

sf::Image *RessourceManager::GetImage(const std::string &ImageLink)
{
    sf::Image *ImgTemp;
    std::map<std::string, sf::Image*>::iterator it;
    it = Images.find(ImageLink);

    if(it == Images.end()) {
        ImgTemp = new sf::Image();
        if(ImgTemp->LoadFromFile(ImageLink)) {
            Images.insert(std::pair<std::string, sf::Image*>(ImageLink, ImgTemp));
        }
    } else {
        ImgTemp = it->second;
    }

    return ImgTemp;
}

sf::Font *RessourceManager::GetFont(const std::string &FontLink) {
    sf::Font *FontTemp;
    std::map<std::string, sf::Font*>::iterator it;
    it = Fonts.find(FontLink);

    if(it == Fonts.end()) {
        FontTemp = new sf::Font();
        if(FontTemp->LoadFromFile(FontLink)) {
            Fonts.insert(std::pair<std::string, sf::Font*>(FontLink, FontTemp));
        }
    } else {
        FontTemp = it->second;
    }

    return FontTemp;
}

sf::SoundBuffer *RessourceManager::GetSound(const std::string &SoundLink) {
    sf::SoundBuffer *SoundTemp;
    std::map<std::string, sf::SoundBuffer*>::iterator it;
    it = Sounds.find(SoundLink);

    if(it == Sounds.end()) {
        SoundTemp = new sf::SoundBuffer();
        if(SoundTemp->LoadFromFile(SoundLink)) {
            Sounds.insert(std::pair<std::string, sf::SoundBuffer*>(SoundLink, SoundTemp));
        }
    } else {
        SoundTemp = it->second;
    }
    return SoundTemp;
}
