# include<bits/stdc++.h>                                                  // It includes all basic Library with it like stl - <vector>,<arra> and iostream etc
using namespace std; 

double cgpaCal(double marks[],int n)                                      // calculate cgpa and return it
{
    double grade[n];                                                      //  using double for precision and accuracy it will definitely take some more stack memory then float takes 
    
    for (int i=0;i<n;i++)                                                 // for loop for converting marks  into grade
    {
        grade[i]=marks[i]/10;                                             // grade is 10th of marks gained 
    }
    
    int sum=0;                                                            // variable for containing sum of all the grades because CGPA is Average of that grade
    for(int i=0;i<n;i++)
    {
        sum+=grade[i];                                                    // inisialy sum was 0 then grade 1 is added to it and then next grad till all graedes
    }
    
    float cgpas=sum/n;                                                    // average of grade = cgpa
    return cgpas;                                                         //returnig a float value with it so we have to store it in a variable in mani() function 
    
}


int main(){
    int n;
    
    cout<<"How many subjects are there "<<endl;                          // asking for n
    cin>>n;
    double marks[n];                                                     //array of n size, taking runtime error risk but don't worry their is no one who can fill full stack memory so that he has done so many subjects in one Exams
    
    for (int i=0;i<n;i++)                                                
    {
        cout<<"Enter marks for "<<i+1<<" subject - "<<endl;
        cin>>marks[i];
    }
    
    float cgpa=cgpaCal(marks,n);
    cout<<" cgpa is - "<<cgpa<<endl;
    cout<<"percentage is - "<<cgpa*9.5<<endl;                           // percentage is cgpa multiplied with 9.5
    
    
}
