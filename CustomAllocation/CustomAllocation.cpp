// CustomAllocation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    
    int i, j, r;
    std::cout << "\n\n Memory allocation in diamond like shape:\n";
    std::cout << "----------------------------------------\n";
    std::cout << " Input number of rows (half of the diamond): ";
    std::cin >> r;


    int numOfCells = 0;
    //calculating number of cells for flat array
    for (int i = 1; i <= r; i++)
        numOfCells += (2 * i - 1);
    for (i = r - 1; i >= 1; i--)
        numOfCells += (2 * i - 1);

    //flat array for memory allocation
    int* pointers = new int[numOfCells];
    //multi-dimension array for pointers
    int*** Cpointers = new int** [(r * 2) - 1];

    //printing number of cells
    std::cout << "numOfCells: " << numOfCells << std::endl;


    //variable for number of overriten Cells
    int overritenCells = 0;

    for (int i = 1; i <= r; i++)
    {
        std::cout << "Position: " << (i - 1) << " Number of cells" << "* " << (2 * i - 1) << std::endl;

        //assigning array for 
        Cpointers[i - 1] = new int*[2 * i - 1];

        //filling flat array
        for (int z = 0; z <  (2 * i - 1); z++) {
            pointers[z + overritenCells] = (i - 1);
            Cpointers[i - 1][z] = &pointers[z + overritenCells];
        }

        overritenCells += (2 * i - 1);
    }
    for (i = r - 1; i >= 1; i--)
    {
        std::cout << "Position: " << (-i + (2 * r)) - 1 << " Number of cells" << "* " << 2 * i - 1 << std::endl;
        
        //assigning array
        Cpointers[(-i + (2 * r)) - 1] = new int*[2 * i - 1];

        //filling array
        for (int z = 0; z < (2 * i - 1); z++) {
            pointers[(-i + (2 * r)) - 1] = (i - 1);
            Cpointers[(-i + (2 * r)) - 1][z] = &pointers[(-i + (2 * r)) - 1];
        }
    }

    std::cout << std::endl << std::endl << std::endl;
    

    //printing tables 
    overritenCells = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int z = 0; z < (2 * i - 1); z++)
            std::cout << Cpointers[i - 1][z] << "(" << *Cpointers[i - 1][z] << ")" << " ";
        std::cout << std::endl;
    }
    for (i = r - 1; i >= 1; i--)
    {
        for (int z = 0; z < (2 * i - 1); z++)
            std::cout << Cpointers[(-i + (2 * r)) - 1][z] << "(" << *Cpointers[(-i + (2 * r)) - 1][z] << ")" << " ";
        std::cout << std::endl;
    }


    std::cout << std::endl << std::endl << std::endl;

    
    std::cout << Cpointers[1][2] << "(" << *Cpointers[1][2] << ")" << std::endl;
    std::cout << Cpointers[1][2] + 1 << "(" << *(Cpointers[1][2] + 1) << ")" << std::endl;

    std::cout << Cpointers[1][3] << std::endl; //still broken :(

  
    system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

