#include <iostream>
#include <vector>
#include<map>
#include<queue>
#include<math.h>
#include<vector>
#include <cassert>
#include <algorithm>
using namespace std;

map<pair<string,string>,float> interconnection;
map<pair<string,string>,float> new_interconnection;
typedef pair<string, string> Pair;
vector<Pair> vec;

vector<float> lay_output[100];
vector <string> layer_info;
map <string,float> node_val;
vector <int> nodes_info;
vector <string> activ;
vector <string> l_type;
vector<vector<float>> In_wt;
vector <float> op_wt;
vector <string> Cur_layer;
vector <string> Prev_layer;
map <string,int> nodes_numbering;

int no_of_iterations;
int iterations = 0;
int iter = 0;
int no_of_layers;
int lcount = -1;

class activation_function
{
    private:
    float x;
    public:
    float relu(float x);
    float sigmoid(float x);
};

float activation_function::relu(float x)
{
    if (x<0)
        return 0;
    else
        return x;
}

float activation_function::sigmoid(float x)
{
    return 1/(1+exp(-x));
}
class Forward:public activation_function
{
    private:
    string cur_layer;
    string prev_layer;
    int count;
    
    public:
    Forward()
    {
        if(lcount==-1)
            cout<<"************************* iteration "<<++iterations<<" ****************************\n";
        count = 0;
        ++lcount;
    }
    activation_function a;
    void nodes(vector<float> input);
    void connections(vector <float> in);
    void compute(vector <float> weights);
};

void Forward::compute(vector <float> weights)
{   
    int c =0;
    cout<<"\nvalue of nodes at layer "<<++iter<<":"<<endl;
    for(int h = 0;h<nodes_info[lcount];h++)
    {   float val = 0;
        
        for(int i = 0; i<lay_output[lcount-1].size(); i++)
        {
            val = val + lay_output[lcount-1][i]*weights[c++];
        }
    val = (activ[lcount]=="relu")?a.relu(val):a.sigmoid(val);
    cout<<val<<" ";
    lay_output[lcount].push_back(val);
    }
    cout<<"\n\n";
}
void Forward::connections(vector <float> weights)
{
    int c = 0;
    cout<<"weights:\n";
    for(int h = 0;h<nodes_info[lcount];h++)
    {
        for(int i = 0; i<nodes_info[lcount-1]; i++)
        {   
            if ((l_type[lcount] == "hidden") && (l_type[lcount-1] == "input")) //check previous layer type
            {
                cur_layer = "H"+to_string(lcount);
                prev_layer = "I";
            }
            
            else if ((l_type[lcount] == "hidden") && (l_type[lcount-1] == "hidden"))
            {
                cur_layer = "H"+to_string(lcount);
                prev_layer = "H"+to_string(lcount-1);
            }
            else
            {
                cur_layer = "O";
                prev_layer = "H"+to_string(lcount-1);
            }
            vec.push_back(make_pair(prev_layer+to_string(i+1),cur_layer+to_string(h+1)));
            interconnection[make_pair(cur_layer+to_string(h+1),prev_layer+to_string(i+1))]=weights[c];
            Prev_layer.push_back(prev_layer+to_string(i+1));
            Cur_layer.push_back(cur_layer+to_string(h+1));
            cout<<cur_layer+to_string(h+1)<<" "<<prev_layer+to_string(i+1)<<" ";
            
            cout<<weights[c]<<"\n";
            c = c + 1;
        }
        nodes_numbering[cur_layer+to_string(h+1)] = (h+1);
    }
}
void Forward::nodes(vector<float> input)
{
    if (l_type[lcount] == "input")
    {   
        for(int i=0;i<input.size();i++)
        {   //input[i] = (activ[lcount]=="relu")?a.relu(input[i]):a.sigmoid(input[i]);
            if(activ[lcount]=="relu")
                input[i] = a.relu(input[i]);
            else if (activ[lcount] == "sigmoid")
                input[i] =a.sigmoid(input[i]);
            lay_output[lcount].push_back(input[i]);
            node_val["I"+to_string(i+1)] = input[i];
            nodes_numbering["I"+to_string(i+1)] = i+1;
        }
    }
    else if ((l_type[lcount] == "hidden") || (l_type[lcount] == "output"))
    {   
         connections(input); // here inputs are weights
         compute(input);
    }
}

class Backward:public Forward
{
    private:
    map <string,float> delta;
 
    float actual_output;
    public:
    Backward(float act_output) 
    {
        actual_output = act_output;
    }
    activation_function b;
    float mse(float pred_output);
    float cost_func_derivative(float pred_output);
    float sigmoid_derivative(float x);
    float relu_derivative(float x);
    float weight_update(float lr);
};

float Backward::mse(float pred_output)
{
    float cost_function = 0.5 * (pow(actual_output,2)-pow(pred_output,2));
    return cost_function;
}

float Backward::cost_func_derivative(float pred_output)
{
    float slope_cost_function = - (actual_output - pred_output);
    return slope_cost_function;
}


float Backward::relu_derivative(float x)
{
    if(x<0)
        return 0;
    else if(x>0)
        return 1;
}


float Backward::sigmoid_derivative(float x)
{
   return x*(1-x);
}

float Backward::weight_update(float lr)
{  
   float derivative;
   cout<<"Loss:"<<mse(lay_output[no_of_layers-1][0])<<"\n\n";

   int no_of_interconnection = interconnection.size();
   reverse(Cur_layer.begin(),Cur_layer.end());
   reverse(Prev_layer.begin(),Prev_layer.end());
   
   int res = 0;
   map<int,int> n_interconnection;
   for(int i=0;i<no_of_layers-1;i++)
   {
       int n = nodes_info[i]*nodes_info[i+1];
       for(int j=0;j<n;j++)
       {
           n_interconnection[res++] = i+1;
       }
   }

   int n = no_of_interconnection;
   int ind = 0;
   for(int i=0;i<no_of_interconnection;i++)
        {   
            int l = n_interconnection[--n];
            
            //cout<<"\n################"<<l<<"################\n";
            //cout<<"current node:"<<Cur_layer[ind]<<"\n"; 
            //cout<<"current node output:"<<lay_output[l][nodes_numbering[Cur_layer[ind]]-1]<<"\n";
            //cout<<"weight to update:"<<interconnection[make_pair(Cur_layer[ind],Prev_layer[ind])]<<"\n";
            //cout<<"prev node:"<<Prev_layer[ind]<<"->"<<lay_output[l-1][nodes_numbering[Prev_layer[ind]]-1]<<"\n";

            if (activ[l] == "sigmoid")
                derivative = sigmoid_derivative(lay_output[l][nodes_numbering[Cur_layer[ind]]-1]);
            else if (activ[l] == "relu")
                derivative = relu_derivative(lay_output[l][nodes_numbering[Cur_layer[ind]]-1]);
 
            if(l == (no_of_layers-1))
            { 
            delta[Cur_layer[ind]] = - cost_func_derivative(lay_output[no_of_layers-1][nodes_numbering[Cur_layer[ind]]-1]) * derivative ;//* node_val[Prev_layer[ind]] ;
            }
            
            else 
            {
            float result = 0;
            for (auto i = vec.begin(), toofar = vec.end(); i != toofar; ++i)
                if (i->first == Cur_layer[ind])
                {
                    result = result + (interconnection[make_pair(i->second,Cur_layer[ind])] * delta[i->second]);
                }
                delta[Cur_layer[ind]] = result * derivative;
            }
            //cout<<"\ndelta is :"<<delta[Cur_layer[ind]]<<"\n";
            new_interconnection[make_pair(Cur_layer[ind],Prev_layer[ind])] = interconnection[make_pair(Cur_layer[ind],Prev_layer[ind])]
                                                                            - (lr * -delta[Cur_layer[ind]] * lay_output[l-1][nodes_numbering[Prev_layer[ind]]-1]);
            ++ind;
        }
        
   for(auto source:new_interconnection)
   {
             op_wt.push_back(new_interconnection[make_pair(source.first.first,source.first.second)]) ;  
   }

   int n_layers_interconnection;

   int co = 0;
   int incr = 0;
   for(int i=0;i<no_of_layers-1;i++)
   {
       n_layers_interconnection = nodes_info[i]*nodes_info[i+1];
       for(int j=0;j<n_layers_interconnection;j++)
       {
           In_wt[i+1][j] = op_wt[j+co];
           incr++;
       }
       
       co = incr;
   }
   op_wt.clear();
   
   for(int i=0;i<no_of_layers;i++)
        lay_output[i].clear();

   iter = 0;
   lcount = -1;
   vector<Forward*> F;
   
   if(iterations!=no_of_iterations)
    for (unsigned int x=0; x<no_of_layers; x++) {
        Forward *layer = new Forward();
        F.push_back(layer);
        layer->nodes(In_wt[x]);
    }
}

int main()
{
    In_wt={ {1,2,-1,1},  //input
            {0.5,0.4,0.1,0.2,0.65,0.15,0.2,0.7},
            {0.1,0.2,0.3,0.4},
            {-0.25,0.5} };
    
    no_of_layers = 4; // no of layers
    nodes_info = {4,2,2,1}; //no of nodes at each layer
    activ = {"None","sigmoid","sigmoid","sigmoid"}; //activation for each layer
    l_type = {"input","hidden","hidden","output"}; //layer types
    
    no_of_iterations = 5;
    float actual_op = 0.6;// actual output
    float learning_rate = 0.2;
    
    vector<Forward*> F;

    for (unsigned int x=0; x<no_of_layers; x++) {
        Forward *layer = new Forward();
        F.push_back(layer);
        layer->nodes(In_wt[x]);
    }
    Backward b(actual_op);
    for (int i=0;i<no_of_iterations;i++)
    {
        b.weight_update(learning_rate);
    }
    return 0;
    
}
