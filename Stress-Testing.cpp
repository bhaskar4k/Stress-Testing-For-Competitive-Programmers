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


// Generate lowercase string of length n
string generate_lowercase_string_of_length_n(int n){
    string s="";

    for(int i=0; i<n; i++){
        int x=(rand()%26);
        s+=(x+97);
    }

    return s;
}


// Generate uppercase string of length n
string generate_uppercase_string_of_length_n(int n){
    string s="";

    for(int i=0; i<n; i++){
        int x=(rand()%26);
        s+=(x+65);
    }

    return s;
}


// Generate upper lower both case string of length n
string generate_both_case_string_of_length_n(int n){
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


// Generates a random vector of length n having values of mini and maxi length
vector<int> generate_vector_of_random_value_length_n(int n, int minimum_element, int maximum_element){
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
//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
// Your working area

// Print input
void print_input(int n, vector<int> &v){
    cout<<"Input"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<n<<endl;
    for(int val : v){
        cout<<val<<" ";
    }cout<<endl<<endl;
}


// Fill your function that you want to test
void your_function(int &n, vector<int> v) {
    sort(v.begin(),v.end());
    cout<<v[1]<<endl;
}


// Write the bruteforce solution
void bruteforce_function(int &n, vector<int> v) {
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
void stress_testing(int &test_case){
    // Create string streams to capture the outputs
    ostringstream oss1, oss2;

    // Redirect standard output to the string streams
    streambuf* oldCout=cout.rdbuf();

    // Generate inputs
    int n=generate_random_number(10);
    vector<int> v=generate_vector_of_random_value_length_n(n,1,3);

    // Print input
    print_input(n,v);

    // Capture output of your_function()
    cout.rdbuf(oss1.rdbuf());
    
    // Call your function by passing same input
    your_function(n,v);
    string output1=oss1.str();
    
    // Capture output of bruteforce_function()
    cout.rdbuf(oss2.rdbuf());

    // Call bruteforce function by passing same input
    bruteforce_function(n,v);
    string output2=oss2.str();

    // Restore standard output
    cout.rdbuf(oldCout);

    // Print final verdict
    print_verdict(output1,output2);
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
        stress_testing(test);
    }

    return 0;
}
//----------------------------------------------------------------------------
