#include<iostream>
#include<fstream>
#include "ArrayStack.cpp"
#include "ArrayQueue.cpp"

using namespace std;

class Player{

public:
    int id;
    int playingTime;
    int enterTime;
    Player()
    {

    }

    Player(int id,int enterTime,int playingTime)
    {
       this->id=id;
       this->playingTime=playingTime;
       this->enterTime=enterTime;
    }

    Player(const Player& ob)
    {
        this->id=ob.id;
        this->playingTime=ob.playingTime;
        this->enterTime=ob.enterTime;
    }

    Player* operator=(const Player &ob)
    {
        id=ob.id;
        playingTime=ob.playingTime;
        enterTime=ob.enterTime;
        return this;

    }


     friend ostream& operator<<(ostream& os,const Player& p);



};

ostream& operator<<(ostream& os,const Player& p) {
    os << p.id <<" " << p.playingTime<< endl;
    return os;
    }


 int match(int x,int* arr)
 {
     int temp=-1;
     for(int i=0;i<8;i++)
     {
         if(x==arr[i])
            temp=i;
     }
     return temp;

 }



  int main()
{
    ifstream infile;
    ofstream outfile;

    Queue<Player>bList;
    Queue<Player>qList;
    Stack<Player>sList;


    infile.open("gamingStore_input.txt");
    outfile.open("gamingStore_output.txt");
    int totalPlayer,totalTime;

     infile >> totalPlayer >> totalTime;

    int  entering_time[totalPlayer];
    int playing_time[totalPlayer];

    int enter,play;
    for(int i=0;i<totalPlayer;i++)
    {
        infile>> enter;
        entering_time[i]=enter;
        infile >> play;
        playing_time[i]=play;
    }


    for(int i=0;i<totalPlayer;i++)
     {
         for(int j=i+1;j<totalPlayer;j++)
         {

            if(entering_time[i]>entering_time[j])
            {
                int temp=entering_time[i];
                entering_time[i]=entering_time[j];
                entering_time[j]=temp;

                int temp2=playing_time[i];
                playing_time[i]=playing_time[j];
                playing_time[j]=temp2;

            }


         }

     }



    int console2=false;
    int startTime2;
    int endTime=entering_time[0]+playing_time[0];
     int idNmb=1;
    for(int i=1;i<=totalTime;i++)
    {
        int value=match(i,entering_time);

        if(value!=(-1))
        {
          Player player(idNmb,i,playing_time[value]);

          if(qList.length()<4)
          {
              qList.enqueue(player);
              idNmb++;
          }
          else
         {
            sList.push(player);
            idNmb++;
            if(console2==false)
            {
                startTime2=i;
                console2=true;
            }
          }

        }

        if(i==endTime)
        {
          Player p=qList.dequeue();
          bList.enqueue(p);
          endTime=endTime+qList.frontValue().playingTime;

        }




    }


int idSeq[totalPlayer];
int exitTime[totalPlayer];

int bListLength=bList.length();
int qListLength=qList.length();
int sListLength=sList.length();

int countNo=0;
idSeq[countNo]=bList.frontValue().id;
exitTime[countNo]=bList.frontValue().enterTime+bList.frontValue().playingTime;
countNo++;

bList.dequeue();

int len1=bList.length();


for(int i=1;i<=len1;i++)
{
   idSeq[countNo]=bList.frontValue().id;
    exitTime[countNo]= exitTime[i-1]+bList.frontValue().playingTime;
    countNo++;
    bList.dequeue();
}


for(int i=0;i<qListLength;i++)
{
    idSeq[countNo]=qList.frontValue().id;
    exitTime[countNo]= exitTime[countNo-1]+qList.frontValue().playingTime;
    qList.dequeue();
    countNo++;
    if(qList.length()==0)
        break;
}

idSeq[countNo]=sList.headValue().id;
exitTime[countNo]= startTime2 + sList.headValue().playingTime;
countNo++;

int v=sList.length()-1;
for(int i=0;i<v;i++)
{
 Player person=sList.pop();
 idSeq[countNo]=person.id;
 exitTime[countNo]= exitTime[countNo-1]+ person.playingTime;
 countNo++;
}

    for(int i=0;i<totalPlayer;i++)
     {
         for(int j=i+1;j<totalPlayer;j++)
         {

            if(idSeq[i]>idSeq[j])
            {
                int temp=idSeq[i];
                idSeq[i]=idSeq[j];
                idSeq[j]=temp;

                int temp2=exitTime[i];
                exitTime[i]=exitTime[j];
                exitTime[j]=temp2;

            }


         }

     }




for(int i=0;i<countNo;i++)
{

    cout << idSeq[i]<< ">";
   cout <<exitTime[i]<< endl;
    outfile << idSeq[i] << " >" << exitTime[i]<< endl;

}




return 0;
}











