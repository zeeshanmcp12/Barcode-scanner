#include <cstdlib>
#include <iostream>

using namespace std;

//Base class
class Item {
	private:
		long int barcode;
		string item_name;

	public:	//starting Default constructor
		Item()
		{
		barcode=0;	//Assigned default value to avoid taking garbage value.
		item_name= "";
		}
		Item ( string z, int k)	// Parameterized Constructor
		{
			barcode=k;
			item_name=z;
		}
			int setbarcode()
			{
				cout << "Enter the barcode:"<<"(sample bc: 070563 and 123456)" <<endl;
				cin >> barcode;
				return 0;
			}
			int getbarcode()
			{
				return barcode;
			}
			string getname()
			{
				return item_name;
			}
			void scanner()
			{
				cout << "Enter the item name: "	<<"(sample : manosalwa and orange)" <<endl;
				cin.ignore();
				getline(cin,item_name);
			}
			void printer()
			{
				cout << "\n**********Description**********\n";
				cout << endl << "Item name : \t\t\t" << item_name;
			}
};
// Starting inheritance of Item class
class PackedFood:public Item{
	int price_per_piece;
	int quantity;

	public:
		PackedFood() :Item()
		{
			price_per_piece=0;	//Assigned default value to avoid taking garbage value.
			quantity=0;
		}
		PackedFood( string z, int x) :Item (z,x)
		{	}
			void setprice()
			{
				cout << "Enter the price: " <<endl;
				cin >> price_per_piece;
				cout << "Enter the quantity: " ;
				cin >> quantity;
			}
			int getprice()
			{
				return price_per_piece;
			}
			void printer()
			{
				cout<< endl<< "Price per item :\t\t"<< price_per_piece<<endl;
				cout<< "\n Quantity: \t\t\t"<<quantity<<endl;
				cout<< "\n Total price of this item: \t" << price_per_piece * quantity;
			}
};
class FreshFood :public Item{
	private:
		double weight;
		double price_per_kilo;

	public:
		FreshFood () :Item()
		{
		weight = 0.0;
		price_per_kilo=0.0;
		}

		FreshFood ( string z, int y) : Item(z,y)
		{}
		void setweight()
		{
			cout << "\nEnter the weight in Grams: ";
			cin >> weight;
		}
		void setprice()
		{
			cout << "\nEnter the price per kilo: ";
			cin >> price_per_kilo;
		}
		void printer()
		{

			cout<< endl<< "Weight of Item :\t\t"<< weight<<" Grams";
			cout<< "\nPrice per kilo : \t\t"<<price_per_kilo<<" Rupees";
			cout<< "\nTotal price of this item: \t" << (weight * price_per_kilo)/1000<<" Rupees";
		}

};


// starting main function
int main()
{
	Item *p, item1, item2 ("",0);

	PackedFood pack1, pack2("manosalwa", 070563);
	FreshFood food1, food2 ("orange", 123456);

	item1.setbarcode();
	item1.scanner();

	if(item1.getbarcode() == pack2.getbarcode() && item1.getname() == pack2.getname())
	{
		p = &pack2;
		pack2.setprice();
		p->printer();
		pack2.printer();
	}
		else if(item1.getbarcode() == food2.getbarcode() && item1.getname() == food2.getname() )
		{
		p = &food2;		//assigned address of food2 to p
		food2.setprice();
		food2.setweight();
		p->printer();
		food2.printer();
		}

		else if(item1.getbarcode() != pack2.getbarcode() && item1.getbarcode() != food2.getbarcode() && item1.getname() != pack2.getname() && item1.getname() != food2.getname() )
		cout<< endl<<"Incorrect Barcode and Item.";

		else if(item1.getbarcode() != pack2.getbarcode() && item1.getbarcode() != food2.getbarcode())
		cout<< endl<<"Barcode not matched";

		else if(item1.getname() != pack2.getname() && item1.getname() != food2.getname())
		cout<< endl << "Item not found";

	cout<<endl;
	system("pause");
	return 0;
}
