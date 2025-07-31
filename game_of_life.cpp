#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <chrono>



std::vector<std::vector<int>> initialise_grid(int N) {

    std::vector<std::vector<int>> grid(N, std::vector<int>(N, 0));


    for (int i = 0; i<N; i++) {
        for (int j = 0 ; j < N; j++) {
            
            if (rand() %2 == 0){
                grid[i][j] = 1;
            }

            else{
                grid[i][j] = 0;
            }

        }
    }


    return grid;
    
}



void visualise(const std::vector<std::vector<int>> grid, int N){

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            std::cout << (grid[i][j] ? "#" : ".") << ' '; 
            //std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}



int wrap(int i, int N) {
    return (i + N) % N;
}




std::vector< std::vector<int> > convolution(const std::vector<std::vector<int>> grid, int N){

    std::vector<std::vector<int>> output(N, std::vector<int>(N, 0));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            
            if (grid[i][j] ==0){
                continue;
            }

            
            // Increment neighbors (with wrapping)
            output[wrap(i-1, N)][wrap(j-1, N)]++;
            output[wrap(i-1, N)][wrap(j  , N)]++;
            output[wrap(i-1, N)][wrap(j+1, N)]++;

            output[wrap(i  , N)][wrap(j-1, N)]++;
            output[wrap(i  , N)][wrap(j+1, N)]++;

            output[wrap(i+1, N)][wrap(j-1, N)]++;
            output[wrap(i+1, N)][wrap(j  , N)]++;
            output[wrap(i+1, N)][wrap(j+1, N)]++;


        }
    }

    return output;


}













int main()
{
 


    int N = 50;

    std::vector<std::vector<int>> grid = initialise_grid(N);


    while(true){

        //sleep
        std::cout << "\033[2J\033[1;1H"; // Clear screen
        visualise(grid, N);


        std::this_thread::sleep_for(std::chrono::milliseconds(100));


        std::vector<std::vector<int>> output = convolution(grid, N);


        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
            
            /*
            live and nn<2 dies
            live and nn=2=3 live
            live and nn>3 dies

            dead and nn==3 live            
            */
            
            int nn = output[i][j];
            
            if (grid[i][j]==1){
                grid[i][j] = (nn==2 || nn==3) ? 1 : 0;
            } else {
                grid[i][j] = (nn == 3) ? 1 : 0;
            }


        //std::cout << "\033[2J\033[1;1H"; // Clear screen












            // if (grid[i][j]==1 && output[i][j]<2){
            //     grid[i][j]=0;
            // }

            // else if (grid[i][j]==1 && 1<output[i][j] && output[i][j]<4)
            // {}

            // else if (grid[i][j]==1 && output[i][j]>3){
            //     grid[i][j]=0;
            // }

            // else if (grid[i][j]==0 && output[i][j]==3){
            //     grid[i][j]=1;
            // }
             
            // else
            // {}

            }
        }




    }



    
    return 0;
}
