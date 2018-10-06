# Neural_network_solver
C++ program to solve a Neural network.

## Forward Pass

![img1](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20net_%7BH11%7D%20%26%3D%20%28w_%7BH11.I1%7D%20*%20I_1%29%20&plus;%20%28w_%7BH11.I2%7D%20*%20I_2%29%20&plus;%20%28w_%7BH11.I3%7D%20*%20I_3%29%20&plus;%20%28w_%7BH11.I4%7D%20*%20I_4%29%5C%5C%20%26%20%3D%20%280.5%20*%201%29%20&plus;%20%280.4%20*%202%29%20&plus;%20%28%200.1%20*%20-1%29%20&plus;%20%280.2%20*%201%29%20%5C%5C%20%26%20%3D%201.4%20%5C%5C%20%5C%5C%20out_%7BH11%7D%20%26%3D%20%5Cfrac%7B1%7D%7B1&plus;e%5E%7B-net_%7BH11%7D%7D%7D%20%5C%5C%20%26%20%3D%20%5Cfrac%7B1%7D%7B1&plus;e%5E%7B-1.4%7D%7D%20%5C%5C%20%26%20%3D%200.802184%20%5C%5C%20%5C%5C%20net_%7BH12%7D%20%26%3D%20%28w_%7BH12.I1%7D%20*%20I_1%29%20&plus;%20%28w_%7BH12.I2%7D%20*%20I_2%29%20&plus;%20%28w_%7BH12.I3%7D%20*%20I_3%29%20&plus;%20%28w_%7BH12.I4%7D%20*%20I_4%29%5C%5C%20%26%20%3D%20%280.65%20*%201%29%20&plus;%20%280.15%20*%202%29%20&plus;%20%28%200.2%20*%20-1%29%20&plus;%20%280.7%20*%201%29%20%5C%5C%20%26%20%3D%201.45%20%5C%5C%20%5C%5C%20out_%7BH12%7D%20%26%20%3D%20%5Cfrac%7B1%7D%7B1&plus;e%5E%7B-net_%7BH12%7D%7D%7D%20%5C%5C%20%26%20%3D%20%5Cfrac%7B1%7D%7B1&plus;e%5E%7B-1.45%7D%7D%20%5C%5C%20%26%20%3D%200.80998%20%5C%5C%20%5C%5C%20%5Cend%7Balign*%7D)


![img2](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20net_%7BH21%7D%20%26%3D%20%28w_%7BH21.H11%7D%20*%20H_%7B11%7D%29%20&plus;%20%28w_%7BH21.H12%7D%20*%20H_%7B12%7D%29%20%5C%5C%20%26%20%3D%20%280.1%20*%200.802184%29%20&plus;%20%280.2%20*%200.80998%29%20%5C%5C%20%26%20%3D%200.43%20%5C%5C%20%5C%5C%20out_%7BH21%7D%20%26%20%3D%20%5Cfrac%7B1%7D%7B1&plus;e%5E%7B-net_%7BH21%7D%7D%7D%20%5C%5C%20%26%20%3D%20%5Cfrac%7B1%7D%7B1&plus;e%5E%7B-0.43%7D%7D%20%5C%5C%20%26%20%3D%200.80998%20%5C%5C%20%5C%5C%20net_%7BH22%7D%20%26%3D%20%28w_%7BH22.H11%7D%20*%20H_%7B11%7D%29%20&plus;%20%28w_%7BH22.H12%7D%20*%20H_%7B12%7D%29%5C%5C%20%26%20%3D%20%280.3%20*%200.802184%29%20&plus;%20%280.4%20*%200.80998%29%20%5C%5C%20%26%20%3D%201%20%5C%5C%20%5C%5C%20out_%7BH22%7D%20%26%20%3D%20%5Cfrac%7B1%7D%7B1&plus;e%5E%7B-net_%7BH22%7D%7D%7D%20%5C%5C%20%26%20%3D%20%5Cfrac%7B1%7D%7B1&plus;e%5E%7B-1%7D%7D%20%5C%5C%20%26%20%3D%200.637529%20%5C%5C%20%5C%5C%20net_%7BO1%7D%20%26%3D%20%28w_%7BO1.H21%7D%20*%20H_%7B21%7D%29%20&plus;%20%28w_%7BO1.H22%7D%20*%20H_%7B22%7D%29%20%5C%5C%20%26%20%3D%20%28-0.25%20*%200.56026%29%20&plus;%20%280.5%20*%200.637529%29%20%5C%5C%20%26%20%3D%200.17%20%5C%5C%20%5C%5C%20out_%7BO1%7D%20%26%3D%20%5Cfrac%7B1%7D%7B1&plus;e%5E%7B-net_%7BO1%7D%7D%7D%20%5C%5C%20%26%20%3D%20%5Cfrac%7B1%7D%7B1&plus;e%5E%7B0.17%7D%7D%20%5C%5C%20%26%20%3D%200.544556%20%5C%5C%20%5C%5C%20%5Cend%7Balign*%7D)


## Calculating the Total Error

![img3](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20E_%7Btotal%7D%20%26%3D%20%5Csum%20%5Cfrac%7B1%7D%7B2%7D%28target%20-%20output%29%5E%7B2%7D%20%5C%5C%20E_%7Bo1%7D%20%26%3D%20%5Cfrac%7B1%7D%7B2%7D%28target_%7BO1%7D%20-%20out_%7BO1%7D%29%5E%7B2%7D%20%5C%5C%20%26%3D%20%5Cfrac%7B1%7D%7B2%7D%280.6%20-%200.544556%20%29%5E%7B2%7D%20%3D%200.001537%20%5C%5C%20%5Cend%7Balign*%7D)

## The Backwards Pass

### Ouput Layer

![img4](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20w_%7BO1.H21%7D%7D%3D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20out_%7BO1%7D%7D%20*%20%5Cfrac%7B%5Cpartial%20out_%7BO1%7D%7D%7B%5Cpartial%20net_%7BO1%7D%7D%20*%20%5Cfrac%7B%5Cpartial%20net_%7BO1%7D%7D%7B%5Cpartial%20w_%7BO1.H21%7D%7D%20%5Cend%7Balign*%7D)

![img5](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20out_%7BO1%7D%7D%20%3D%20-%28target_%7BO1%7D%20-%20out_%7BO1%7D%29%20%3D%20-%280.6%20-%200.544556%29%20%3D%200.055444%20%5Cend%7Balign*%7D)

![img6](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20out_%7BO1%7D%20%26%3D%20%5Cfrac%7B1%7D%7B1&plus;e%5E%7B-net_%7BO1%7D%7D%7D%20%5C%5C%20%5Cfrac%7B%5Cpartial%20out_%7Bo1%7D%7D%7B%5Cpartial%20net_%7Bo1%7D%7D%20%26%3D%20out_%7Bo1%7D%281%20-%20out_%7Bo1%7D%29%20%3D%200.544556%281%20-%200.544556%29%20%3D%200.248014762%20%5Cend%7Balign*%7D)

![img7](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20net_%7BO1%7D%20%26%3D%20w_%7BO1.H21%7D%20*%20out_%7BH21%7D%20&plus;%20w_%7BO1.H22%7D%20*%20out_%7BH22%7D%20%5C%5C%20%5Cfrac%7B%5Cpartial%20net_%7BO1%7D%7D%7B%5Cpartial%20w_%7BO1.H21%7D%7D%20%26%3D%201%20*%20out_%7BH21%7D%20*%20%28w_%7BO1.H21%7D%29%5E%7B%281%20-%201%29%7D%20&plus;%200%20%3D%20out_%7BH21%7D%20%3D%200.56026%20%5Cend%7Balign*%7D)

![img8](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20w_%7BO1.H21%7D%7D%20%26%3D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20out_%7BO1%7D%7D%20*%20%5Cfrac%7B%5Cpartial%20out_%7BO1%7D%7D%7B%5Cpartial%20net_%7BO1%7D%7D%20*%20%5Cfrac%7B%5Cpartial%20net_%7BO1%7D%7D%7B%5Cpartial%20w_%7BO1.H21%7D%7D%20%5C%5C%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20w_%7BO1.H21%7D%7D%20%26%3D%200.055444%20*%200.248014762%20*%200.56026%20%3D%200.007704096302%20%5Cend%7Balign*%7D)

![img9](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20w_%7BO1.H21%7D%7D%20%3D%20-%28target_%7BO1%7D%20-%20out_%7BO1%7D%29%20*%20out_%7BO1%7D%281%20-%20out_%7BO1%7D%29%20*%20out_%7BH21%7D%20%5Cend%7Balign*%7D)

Alternatively, we have ![img10](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B80%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20out_%7BO1%7D%7D%20%5Cend%7Balign*%7D) and ![img11](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B80%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20out_%7BO1%7D%7D%7B%5Cpartial%20net_%7BO1%7D%7D%20%5Cend%7Balign*%7D) which can be written as ![img12](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B80%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20net_%7BO1%7D%7D%20%5Cend%7Balign*%7D) , aka ![img13](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B80%7D%20%5Cbegin%7Balign*%7D%20%5Cdelta_%7BO1%7D%20%5Cend%7Balign*%7D) (the Greek letter delta) aka the node delta. We can use this to rewrite the calculation above:

![img14](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cdelta_%7BO1%7D%20%3D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20out_%7BO1%7D%7D%20*%20%5Cfrac%7B%5Cpartial%20out_%7BO1%7D%7D%7B%5Cpartial%20net_%7BO1%7D%7D%20%3D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20net_%7BO1%7D%7D%20%5Cend%7Balign*%7D)

![img15](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cdelta_%7BO1%7D%20%3D%20-%28target_%7BO1%7D%20-%20out_%7BO1%7D%29%20*%20out_%7BO1%7D%281%20-%20out_%7BO1%7D%29%20%5Cend%7Balign*%7D)

Therefore:
![img16](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20w_%7BO1.H21%7D%7D%20%3D%20%5Cdelta_%7BO1%7D%20out_%7BH21%7D%20%5Cend%7Balign*%7D)

Some sources extract the negative sign from \delta so it would be written as:
![img17](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20w_%7BO1.H21%7D%7D%20%3D%20-%5Cdelta_%7BO1%7D%20out_%7BH21%7D%20%5Cend%7Balign*%7D)

To decrease the error, we then subtract this value from the current weight (optionally multiplied by some learning rate, eta, which we’ll set to 0.2):

![img18](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20w_%7BO1.H21%7D%5E%7B&plus;%7D%20%3D%20w_%7BO1.H21%7D%20-%20%5Ceta%20*%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20w_%7BO1.H21%7D%7D%20%3D%20-0.25%20-%20%28-%200.2%20*%200.007704096302%29%20%3D%20-0.24845918%20%5Cend%7Balign*%7D)

similarly 
![img19](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20w_%7BO1.H22%7D%5E%7B&plus;%7D%20%3D%200.501753%20%5Cend%7Balign*%7D)

### Hidden Layer

![img20](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20w_%7BH21.H11%7D%7D%20%3D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20out_%7BH21%7D%7D%20*%20%5Cfrac%7B%5Cpartial%20out_%7BH21%7D%7D%7B%5Cpartial%20net_%7BH21%7D%7D%20*%20%5Cfrac%7B%5Cpartial%20net_%7BH21%7D%7D%7B%5Cpartial%20w_%7BH21.h11%7D%7D%20%5Cend%7Balign*%7D)

![img21](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20out_%7BH21%7D%7D%20%3D%20%5Cfrac%7B%5Cpartial%20E_%7BO1%7D%7D%7B%5Cpartial%20out_%7BH21%7D%7D%20%5Cend%7Balign*%7D)

![img22](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7BO1%7D%7D%7B%5Cpartial%20out_%7BH21%7D%7D%20%3D%20%5Cfrac%7B%5Cpartial%20E_%7BO1%7D%7D%7B%5Cpartial%20net_%7BO1%7D%7D%20*%20%5Cfrac%7B%5Cpartial%20net_%7BO1%7D%7D%7B%5Cpartial%20out_%7BH21%7D%7D%20%5Cend%7Balign*%7D)

![img23](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7BO1%7D%7D%7B%5Cpartial%20net_%7BO1%7D%7D%20%3D%20%5Cfrac%7B%5Cpartial%20E_%7BO1%7D%7D%7B%5Cpartial%20out_%7BO1%7D%7D%20*%20%5Cfrac%7B%5Cpartial%20out_%7BO1%7D%7D%7B%5Cpartial%20net_%7BO1%7D%7D%20%3D%200.055444%20*%200.2480144762%20%3D%200.013750914%20%5Cend%7Balign*%7D)



And ![img24](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B80%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20net_%7BO1%7D%7D%7B%5Cpartial%20out_%7BH21%7D%7D%20%5Cend%7Balign*%7D) is equal to ![img25](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B80%7D%20%5Cbegin%7Balign*%7D%20w_%7BH21.H11%7D%20%5Cend%7Balign*%7D)


![img25](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cbegin%7Balign*%7D%20net_%7BO1%7D%20%3D%20w_%7BO1.H21%7D%20*%20out_%7BH21%7D%20&plus;%20w_%7BO1.H22%7D%20*%20out_%7BH22%7D%20%5Cend%7Balign*%7D)

![img26](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20net_%7BO1%7D%7D%7B%5Cpartial%20out_%7BH21%7D%7D%20%3D%20w_%7BO1.H21%7D%20%3D%20-0.25%20%5Cend%7Balign*%7D)

![img27](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7BO1%7D%7D%7B%5Cpartial%20out_%7BH21%7D%7D%20%3D%20%5Cfrac%7B%5Cpartial%20E_%7BO1%7D%7D%7B%5Cpartial%20net_%7BO1%7D%7D%20*%20%5Cfrac%7B%5Cpartial%20net_%7BO1%7D%7D%7B%5Cpartial%20out_%7BH21%7D%7D%20%3D%200.013750914%20*%20-0.25%20%3D%20-0.0034377285%20%5Cend%7Balign*%7D)

![img28](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20out_%7BH21%7D%7D%20%3D%20%5Cfrac%7B%5Cpartial%20E_%7BO1%7D%7D%7B%5Cpartial%20out_%7BH21%7D%7D%20%3D%20-0.0034377285%20%5Cend%7Balign*%7D)

we have ![img29](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B80%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20out_%7BH21%7D%7D%20%5Cend%7Balign*%7D)  ,we need to figure out ![img30](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B80%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20out_%7BH21%7D%7D%7B%5Cpartial%20net_%7BH21%7D%7D%20%5Cend%7Balign*%7D)  and then ![img31](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B80%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20net_%7BH21%7D%7D%7B%5Cpartial%20w%7D%20%5Cend%7Balign*%7D) for each weight:

![img32](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20out_%7BH21%7D%20%3D%20%5Cfrac%7B1%7D%7B1&plus;e%5E%7B-net_%7BH21%7D%7D%7D%20%5Cend%7Balign*%7D)

![img33](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20out_%7BH21%7D%7D%7B%5Cpartial%20net_%7BH21%7D%7D%20%3D%20out_%7BH21%7D%281%20-%20out_%7BH21%7D%29%20%3D%200.56026%20*%20%281-0.56026%29%20%3D%200.246368732%20%5Cend%7Balign*%7D)

We calculate the partial derivative of the total net input to ![img34](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20H_%7B21%7D%20%5Cend%7Balign*%7D) with respect to ![img35](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20w_%7BH21.H11%7D%20%5Cend%7Balign*%7D) the same as we did for the output neuron:

![img36](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20net_%7BH21%7D%20%3D%20%28w_%7BH21.H11%7D%20*%20H_%7B11%7D%29%20&plus;%20%28w_%7BH21.H12%7D%20*%20H_%7B12%7D%29%20%5Cend%7Balign*%7D)

![img37](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20net_%7BH21%7D%7D%7B%5Cpartial%20w_%7BH21.H11%7D%7D%20%3D%20H_%7B11%7D%20%3D%200.802184%20%5Cend%7Balign*%7D)

![img38](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20w_%7BH21.H11%7D%7D%20%3D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20out_%7BH_%7B21%7D%7D%7D%20*%20%5Cfrac%7B%5Cpartial%20out_%7BH_%7B21%7D%7D%7D%7B%5Cpartial%20net_%7BH_%7B21%7D%7D%7D%20*%20%5Cfrac%7B%5Cpartial%20net_%7BH_%7B21%7D%7D%7D%7B%5Cpartial%20w_%7BH21.H11%7D%7D%20%5Cend%7Balign*%7D)

![img39](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20w_%7BH21.H11%7D%7D%20%3D%20-0.0034377285%20*%200.246368732%20*%200.802184%20%3D%200.0006872264573%20%5Cend%7Balign*%7D)

![img40](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20w_%7BH21.H11%7D%7D%20%26%3D%20%28%5Csum%5Climits_%7Bo%7D%7B%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20out_%7Bo%7D%7D%20*%20%5Cfrac%7B%5Cpartial%20out_%7Bo%7D%7D%7B%5Cpartial%20net_%7Bo%7D%7D%20*%20%5Cfrac%7B%5Cpartial%20net_%7Bo%7D%7D%7B%5Cpartial%20out_%7BH_%7B21%7D%7D%7D%7D%29%20*%20%5Cfrac%7B%5Cpartial%20out_%7BH_%7B21%7D%7D%7D%7B%5Cpartial%20net_%7BH_%7B21%7D%7D%7D%20*%20%5Cfrac%7B%5Cpartial%20net_%7BH_%7B21%7D%7D%7D%7B%5Cpartial%20w_%7BH21.H11%7D%7D%20%5C%5C%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20w_%7BH21.H11%7D%7D%20%26%3D%20%28%5Csum%5Climits_%7Bo%7D%7B%5Cdelta_%7Bo%7D%20*%20w_%7Bho%7D%7D%29%20*%20out_%7BH_%7B21%7D%7D%281%20-%20out_%7BH_%7B21%7D%7D%29%20*%20H_%7B11%7D%20%5C%5C%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20w_%7BH21.H11%7D%7D%20%26%3D%20%5Cdelta_%7BH_%7B21%7D%7DH_%7B11%7D%20%5Cend%7Balign*%7D)

![img41](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Cbegin%7Balign*%7D%20w_%7BH21.H11%7D%5E%7B&plus;%7D%20%3D%20w_%7BH21.H11%7D%20-%20%5Ceta%20*%20%5Cfrac%7B%5Cpartial%20E_%7Btotal%7D%7D%7B%5Cpartial%20w_%7BH21.H11%7D%7D%20%3D%200.1%20-%20%280.2%20*%20-0.0006872264573%29%20%3D%200.099862554%20%5Cend%7Balign*%7D)

Similarly all the weights can be find out using the same as given above.



