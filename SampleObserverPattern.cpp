#include <iostream>
#include <map>

using namespace std;

class ICustomer
{
    public:
        virtual void update(string status) = 0;
        virtual void getStatus() = 0;
        virtual string getProductName() = 0;
};

class CustomerA : public ICustomer
{
    public:
        string status;
        string product;

        CustomerA(string product)
        {
            this->product = product;
        }

        void update(string status)
        {
            this->status = status;
            getStatus();
        }

        void getStatus()
        {
            string currentStatus = product + " is " + status + " for customer A";
            cout << currentStatus << endl;
        }

        string getProductName()
        {
            return product;
        }
};

class CustomerB : public ICustomer
{
    public:
        string status;
        string product;

        CustomerB(string product)
        {
            this->product = product;
        }

        void update(string status)
        {
            this->status = status;
            getStatus();
        }

        void getStatus()
        {
            string currentStatus = product + " is " + status + " for customer B";
            cout << currentStatus << endl;
        }

        string getProductName()
        {
            return product;
        }        
};

class CustomerC : public ICustomer
{
    public:
        string status;
        string product;

        CustomerC(string product)
        {
            this->product = product;
        }

        void update(string status)
        {
            this->status = status;
            getStatus();
        }

        void getStatus()
        {
            string currentStatus = product + " is " + status + " for customer C";
            cout << currentStatus << endl;
        }

        string getProductName()
        {
            return product;
        }        
};

class Shop
{
    public:
        multimap<string, ICustomer*> customers;

        void subscribeCustomer(ICustomer *customer)
        {
            customers.insert(pair<string, ICustomer*>(customer->getProductName(), customer));
        }

        void unsubscribeCustomer(string product)
        {
            map<string, ICustomer*>::iterator itr; 
            for(itr = customers.begin(); itr != customers.end(); ++itr)
            {
                if (itr->first == product)
                {
                    customers.erase(product);
                }
            }
        }

        void notifyCustomers(string product)
        {
            map<string, ICustomer*>::iterator itr; 
            for(itr = customers.begin(); itr != customers.end(); ++itr)
            {
                if (itr->first == product)
                {
                    itr->second->update("available");
                    break;
                }
                
            }
        }    
};

int main()
{
    Shop shop;
    shop.subscribeCustomer(new CustomerA("Iphone"));
    shop.subscribeCustomer(new CustomerB("Nokia"));
    shop.subscribeCustomer(new CustomerC("Iphone"));
    shop.subscribeCustomer(new CustomerA("Nokia"));

    shop.notifyCustomers("Iphone");
    shop.notifyCustomers("Nokia");

    shop.unsubscribeCustomer("Iphone");
}