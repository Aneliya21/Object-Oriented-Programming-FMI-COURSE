#include <iostream>
#include "_Playlist.h"

int main()
{
    Playlist pl;
    pl.addToPlaylist("Song 2", 0, 1, 55, "rp", "song2.txt");
   // pl.addToPlaylist("Song 1", 0, 1, 5, "p", "song1.txt");

    pl.printPlaylist();

    /*pl.printPlaylist();

    std::cout << std::endl;

    pl.sortByName();
    pl.printPlaylist();

    std::cout << std::endl;

    pl.searchByName("Song 1");

    std::cout << std::endl;

    pl.searchByGenre('r');

    std::cout << std::endl;*/

    //pl.addToPlaylist("Song 3", 0, 2, 33, "h", "file.txt");

    //pl.printPlaylist();

    //pl.addRithmToSongByName("Song 3", 3);

    //pl.serializeSongByNameToBinaryFile("Song 3", "s3.txt");
     //pl.mix("Song 1", "Song 2");

     pl.serializeSongByNameToBinaryFile("Song 2", "song3.txt");

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
