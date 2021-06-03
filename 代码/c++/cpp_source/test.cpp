#include<iostream>
using  namespace std;
class Student{
private: int  score;
public:
   int num;
	Student()
	{   num = number; number++;}
    static int  jige;
    static int  bujige;
	static int  number;
    void setscore(int s)
    {
        score=s;
    }
    friend  double average(Student *x,int n)
    {
        double sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=x[i].score;
        }
        return sum/n;
    }

    static  void  setjige()
    {
        jige++;
    }
    static  void setbujige()
    {
        bujige++;
    }
	static int showbujige()
	{  return bujige;  }
	static int showjige()
	{ return jige;  }
     int showscore()
      {
          return score;
      }
	  int getnumber()
	  {
	  return num;
	  }

};
int Student::bujige=0;
int Student::jige=0;
int Student::number=200001;
int main()
{
  int n ;
   cin>>n;
   if(n<=0)
   return 0;
  Student *student = new Student[n];

  int x;
  for(int i=0;i<n;i++)
  {
      cin>>x;
      try {
          if(x>100 || x<0)
          {
              throw x;
          }
          else
          {
               student[i].setscore(x);
              if(x>=60)
               Student::setjige();
              else Student::setbujige();

          }
      }
      catch(int x)
      {
          cout<<x<<" is invalid!"<<endl;
          i--;
          continue;
      }

  }
  for(int i=0;i<n;i++)
  { cout<<"[学号："<<student[i].getnumber()<<"，成绩"<<student[i].showscore()<<']'<<endl;}
  double k=average(student,n);
  cout<<"Average is :"<<k<<endl;
  cout<<"Number of pass is :";
  cout<<Student::showjige() ;
  cout<<endl;
 cout<<"Number of No pass is :"<<Student::showbujige()<<endl;

}
