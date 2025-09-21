using int2=pair<int,int>;           // (price, shop)
using int3=tuple<int,int,int>;      // (price, shop, movie)
static set<int2> Movie[10001];      // movie->set(price,shop)
struct int2Hash{
    size_t operator()(const int2 x) const{
        // Mersenne prime p=2^31-1
        return ((size_t)x.first<<31u)-x.first+x.second;
    }
};
class MovieRentingSystem {
public:
    unordered_map<int2, int, int2Hash> Shop;// (shop,movie)->price
    set<int3> rented;                      // rented->set (price,shop,movie)

    int mm=10001, MM=0;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop=e[0], movie=e[1], price=e[2];
            Shop[{shop,movie}]=price;
            Movie[movie].insert({price, shop});
            mm=min(mm, movie);
            MM=max(MM, movie);
        }
    }
    ~MovieRentingSystem(){
        fill(Movie+mm, Movie+MM+1, set<int2>());
    }
    vector<int> search(int movie) {
        vector<int> ans;
        auto& S=Movie[movie];
        int i=0;
        for (auto it=S.begin(); it!=S.end() && i<5; it++, i++) {
            ans.push_back(it->second); // shop
        }
        return ans;
    }

    void rent(int shop,int movie) {
        int price=Shop[{shop,movie}];
        Movie[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop,int movie) {
        int price=Shop[{shop,movie}];
        Movie[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int i=0;
        for (auto it=rented.begin(); it!=rented.end() && i<5; it++, i++) {
            auto [price, shop, movie]=*it;
            ans.push_back({shop, movie});
        }
        return ans;
    }
};