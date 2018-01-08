#include <iostream>
#include <string.h>

using namespace std;

class Object
{
    public:
        virtual void print()
        {
            void *a = this;
            cout << a;

        }

        virtual int equals (Object* obj)
        {
            if(this == obj)
                return 1;
            else
                return 0;
        }

        friend int operator == ( Object& obj1, Object& obj2)
        {
            return obj1.equals(&obj2);
        }
};


class String: public Object
{
	private:
		char* chr;
	public:
		String(char * a)
		{
			chr = new char;
			strcpy(chr, a);
		}
		void print()
   	    {
   			cout << chr;
   		}
   int equals (String* obj)
   {
  		if(strcmp(chr, obj->chr) == 0)
   			return 1;
   		else
            return 0;
   }

   friend char* operator+ ( String& ob1, String& ob2)
   {
   		char *sir = new char [strlen(ob1.chr) + strlen(ob2.chr) + 1];
   		strcpy(sir, "");
   		strcat(sir, ob1.chr);
   		strcat(sir, ob2.chr);
   		return sir;
   }
};


class Vector
{
	private:
		Object** vec;
		int n;

	public:
		Vector (int dim)
		{
		    vec = new Object*[dim];
		    n = 0;
		}

		void add (Object& sir)
		{
		    vec[n]= &sir;
		    n++;
		}

		int contains (Object& a)
		{
		    for(int i=0; i<n; i++)
                if(vec[i]->equals(&a))
                    return 1;
                else
                    return 0;
		}

		void print()
		{
		    for(int i=0; i<n; i++)
            {
                vec[i]->print();
                cout << ",";
            }
            cout << endl;
		}

		Object* &operator[] (int pozitie)
        {
            return vec[pozitie];
        }
};

int main(void)
{
	int dim;
	char aux[50]; /// variabila auxiliara in care voi adauga sirurile

	/// creez un obiect al clasei Vector cu dimensiunea specificata de utilizator
	cout << "Ce dimensiune va avea vectorul? ";
	cin >> dim;
	Vector vec(dim);
	cout << "\nIntroduceti cele " << dim << " siruri:" << endl;
	for(int i=0; i<dim; i++)
    {
        cout << i+1 << ". ";
        cin >> aux;
        String* sir = new String(aux);
        vec.add(*sir);
    }

    /// accesez sirul de pe pozitia "i" cu ajutorul operatorului [] si afisez vectorul
    cout << "\nVectorul este: ";
    for(int i=0; i<dim; i++)
    {
        vec[i]->print();
        cout << " ";
    }

//    cout << "\nCe element doriti sa verificati daca exista? ";
//    cin >> aux;
//    String* s = new String(aux);
//    if(vec.contains(s) == 0)
//        cout << "\nElementul apartine vectorului!";
//    else
//        cout << "\nElementul nu apartine vectorului!";

	return 0;

}
