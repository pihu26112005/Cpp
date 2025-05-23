
class Solution {
    public:
        int rangeBitwiseAnd(int left, int right) {
            int cnt = 0;
            while (left != right) {
                left >>= 1;
                right >>= 1;
                cnt++;
            }
            return (left << cnt);
        }
    };
    
    
    // logic - hum left and right ko right shift tab tak kr rhe hai, jab tak vo barabar nhi hote
    // then utni  jagah zero bhar rhe hai 
    
    // eg = 
    // left  = 26 → 11010  
    // right = 30 → 11110 
    
    // Shifting:
    
    // 1: 1101 , 1111  
    // 2: 110 , 111  
    // 3: 11 , 11 → equal!
    
    // cnt = 3  
    // left = 11 → shift back: 11 << 3 = **11000** = 24
    
    
    // reason -
    // 1- 
    // jo bits sab number me common hai like sabe me 1 hai us position pe ya 0, 
    // then and krke vo bit same hi aayegi 
    // but agar koi position pe ek bhi bit differ hui toh and usko zero hi kr dega 
    // 2- 
    // now socho like 26 = 11010 , 27 = 11011, we have to add 1 to get n+1 from n in binary 
    // so n and n+1 minimum ek bit se toh differ honge hi, so n+1 and n+2 bhi ek bit se differ 
    // so aise left se shuru krke right tak har number min ek bit se differ krega 
    // aur ye difference right side se create hota jaa rha hai, kyokii 1 right bit me add hota hai 
    // so left and right me left se jitni bit same hongi vo unke bich ke har number me same hongi
    // and so right se jaha ak bit differ krengi dono me vahan tak toh bich ke numbers me bhi differ hongi and ultimately vo zero kr dega and 
    
    // “These top bits are common in all numbers from left to right. Only they can survive the AND.”
    
    