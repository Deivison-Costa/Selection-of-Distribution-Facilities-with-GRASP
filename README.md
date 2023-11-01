# Selection of Distribution Facilities with GRASP
## Problem statement:
- You are responsible for selecting cities to build distribution facilities with the goal of minimizing the total cost of transportation. You have a set of cities, each with geographic coordinates (latitude and longitude) and a distance matrix that represents the cost of transportation between the cities. The goal is to decide which cities will build distribution facilities in a way that minimizes transportation costs.
## Decision Variables:
- Binary variable x_i for each city i, where x_i equals 1 if a distribution facility is built in city i and 0 otherwise.

## Objective Function:
- Minimize the total transportation cost, which is a linear function of the decision variables:
- Minimize Z = Σ Σ (d_ij * x_i * x_j), where d_ij is the distance (transport cost) between cities i and j.

## Restrictions:
- Each city can have a maximum of one distribution facility:
- Σ x_i ≤ 1, for all i.
- A maximum number of distribution facilities must be constructed:
- Σ x_i ≤ K, where K is a given value.
- 
## Requirements
- C++ compiler that supports C++11 or higher.

## Usage

1. Clone the repository:

   ```shell
   git clone https://github.com/seu-usuario/Selection-of-Distribution-Facilities-with-GRASP.git
2. Compile the code:
   ```shell
   g++ -std=c++11 main.cpp -o grasp_distribution
3. Run the program:
   ```shell
   ./grasp_distribution
