#include <iostream>
#include <cstring>
using namespace std;


class Takplate 
{
    private:
    char navn[20];
    int lengde, bredde; // i cm

    public:

    // OK
    Takplate(char* t, int l, int b)
        { strcpy(navn, t); lengde = l; bredde = b; }
    
    // 3. LENGDE 'x' => LENGDE << 'x' 
    void print() { std::cout << navn << ": " << LENGDE 'x' << bredde << '\n'; }
    
    // OK 
    float areal() { return ((lengde/100.0F) * (bredde/100.0F)); } // i kvm

    // 4. areal => areal()
    // 5. rhs->areal() => rhs.areal() 
    bool operator < (Takplate & rhs) { return (areal < rhs->areal()); }

    // OK  
    int antPlater(int kvm) { return (kvm / areal()); }
};

int main() {

  // 1. , => ;  
  Takplate * tp1 = new Takplate("Decra", 126, 37),  

  // 2. tp2 => Takplate* tp2
  tp2 = new Takplate("Plannja", 500, 115);

  tp1->print(); 
  (*tp2).print();

        std::cout << "Deres areal i kvm: "
                << (*tp1).areal() 
                << " " 
                << tp2->areal() << '\n';

        std::cout << "Til 190 kvm trengs henholdsvis minimum " 
                << tp1->antPlater(190)
                << " og "

                // tp2->antPlater(180) => tp2->antPlater(190)
                << tp2->antPlater(180) << " plater\n";

        return 0;
}
