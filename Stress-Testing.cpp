#include <bits/stdc++.h>
using namespace std;


// Paste by your CP template over here -------------------------------------

// CP Template ending -----------------------------------------------------------------------------------------




//----------------------------------------------------------------------------
// Utility functions (Don't modify this)

// Generates random number from 1 to range
int generate_random_number(int range){
    return (rand()%range)+1; 
}


// Generate random lowercase string of length n
string generate_random_lowercase_string_of_length_n(int n){
    string s="";

    for(int i=0; i<n; i++){
        int x=(rand()%26);
        s+=(x+97);
    }

    return s;
}


// Generate random uppercase string of length n
string generate_random_uppercase_string_of_length_n(int n){
    string s="";

    for(int i=0; i<n; i++){
        int x=(rand()%26);
        s+=(x+65);
    }

    return s;
}


// Generate random upper & lower both case string of length n
string generate_random_both_case_string_of_length_n(int n){
    string s="";

    for(int i=0; i<n; i++){
        int x=(rand()%26);
        int type=(rand()%2);
        
        if(type==0){
            s+=(x+65);
        }else{
            s+=(x+97);
        }
    }

    return s;
}


// Generate random numeric string of length n
string generate_random_numeric_string_of_length_n(int n){
    string s="";

    for(int i=0; i<n; i++){
        int x=(rand()%10);
        s+=(x+48);
    }

    return s;
}


// Generates a random vector of length n having values in between mini and maxi
vector<int> generate_vector_of_random_value_of_length_n(int n, int minimum_element, int maximum_element){
    vector<int> v;
    
    for(int i=0; i<n; i++){
        int random_value=minimum_element+rand()%(maximum_element-minimum_element+1);

        v.emplace_back(random_value);
    }

    return v;
}


// Print captured outputs and final verdicts
void print_verdict(string &output1, string &output2){  
    cout<<"Output Of Your Function"<<endl;
    cout<<"------------------------"<<endl;
    cout<<output1<<endl;

    cout<<"Output Of Bruteforce Function"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<output2<<endl;

    // Compare the outputs
    if(output1==output2){
        cout<<"Verdict - [OK]"<<endl;
    }else{
        cout<<"Verdict - [NOT OK]"<<endl;
    }

    cout<<"____________________________________________________________________________"<<endl<<endl<<endl;
}


// Final verdict judging
void get_final_verdict(string output1, string output2, streambuf* &oldCout){
    // Restore standard output
    cout.rdbuf(oldCout);

    // Print final verdict
    print_verdict(output1,output2);
}
//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
// Your working area

// Print inputs to see the generated testcase
void print_input(int n, vector<int> &v){ // Update parameters by generated inputs
    cout<<"Input"<<endl;
    cout<<"--------------------------"<<endl;

    // Update printing statements of inputs to see the generated testcases
    cout<<n<<endl;
    for(int val : v){
        cout<<val<<" ";
    }cout<<endl<<endl;
}


// Fill your function that you want to test
void your_function(int &n, vector<int> v) { // Update parameters by generated inputs
    if(v.size()<2){
        cout<<"No second smallest"<<endl;
        return;
    }

    sort(v.begin(),v.end());
    cout<<v[1]<<endl;
}


// Write the bruteforce solution
void bruteforce_function(int &n, vector<int> v) { // Update parameters by generated inputs
    int mini=1e9;
    for(int i=0; i<n; i++){
        mini=min(mini,v[i]);
    }

    int second_smallest=1e9;
    for(int i=0; i<n; i++){
        if(v[i]<second_smallest && v[i]!=mini){
            second_smallest=v[i];
        }
    }

    if(second_smallest==1e9){
        cout<<"No second smallest"<<endl;
    }else{
        cout<<second_smallest<<endl;
    }
}


// Stress testing function
void stress_testing(int &test_case, ostringstream &oss1, ostringstream &oss2, streambuf* &oldCout){
    // Generate inputs ---------------------------------------------------------------------------
    int n=generate_random_number(10);
    vector<int> v=generate_vector_of_random_value_of_length_n(n,1,3);

    // Print inputs
    print_input(n,v); // Update parameters by generated inputs
    //--------------------------------------------------------------------------------------------


    // Calling your_function() -------------------------------------------------------------------
    cout.rdbuf(oss1.rdbuf()); // Capture output of your_function() 
    
    your_function(n,v); // Update parameters by generated inputs
    //--------------------------------------------------------------------------------------------
    

    // Calling bruteforce_function() -------------------------------------------------------------
    cout.rdbuf(oss2.rdbuf()); // Capture output of bruteforce_function()

    bruteforce_function(n,v); // Update parameters by generated inputs
    //--------------------------------------------------------------------------------------------

    get_final_verdict(oss1.str(),oss2.str(),oldCout);
}
//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
// Main function 
int main(){
    int test_case=100; // Change the number of test cases according to your need.
    srand(static_cast<unsigned int>(time(0)));

    for(int test=1; test<=test_case; test++){
        cout<<"-----------------------------------"<<endl;
        cout<<"|          Test Case - "<<test<<"          |"<<endl;
        cout<<"-----------------------------------"<<endl<<endl;

        // Create string streams to capture the outputs
        ostringstream oss1, oss2;

        // Redirect standard output to the string streams
        streambuf* oldCout=cout.rdbuf();

        stress_testing(test,oss1,oss2,oldCout);
    }

    return 0;
}
//----------------------------------------------------------------------------
