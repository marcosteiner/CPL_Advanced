#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ostream>
#include <utility>
#include <chrono>

struct Tracer {
  std::string name;

  explicit Tracer(std::string name = "") : name { name } {
    //std::cout << "Tracer created: " << name << std::endl;
  }

  //Exercise 3
  Tracer(Tracer && tracer) noexcept : name{std::move(tracer.name)} {
	  //std::cout << "Tracer move constructed: " << name << std::endl;
	  tracer.name = this->name + "";
  }

  Tracer& operator=(Tracer&& other) {
	std::swap(this->name, other.name);
	other.name = other.name + " moved to";
	this->name = this->name + " move-assigned";
	return *this;
  }

  ~Tracer() {
    //std::cout << "Tracer destroyed: " << name << std::endl;
  }

  /* Outcommented for exercise 3
  Tracer(Tracer const& other) : name { other.name + " copy" } {
    std::cout << "Tracer copied: " << name << std::endl;
  }*/
  void show() const {
    std::cout << "Tracer: " << name << std::endl;
  }

/* Outcommented for exercise 3
  Tracer& operator=(Tracer const& other) {
	this->name= other.name + " copy";
	return *this;
  }*/

};

void foo(Tracer t) {
  Tracer trace{"foo"};
  t.show();
}

Tracer bar(Tracer const &t) {
  Tracer trace{"bar"};
  t.show();
  return trace;
}

//Exercise 1
/*
int main() {
  Tracer m{"main"};
  {
    Tracer inner{"inner"};
    foo(inner);
    auto trace = bar(inner);
    trace.show();
    inner.show();
  }
  foo(Tracer{"temp"});
  m.show();
}*/

//Exercise 2
/*
int main() {
	std::vector<Tracer> v{};
	v.push_back(Tracer{"T1"});
	v.push_back(Tracer{"T2"});
	v.push_back(Tracer{"T3"});
	v.push_back(Tracer{"T4"});

	std::vector<Tracer> const v_copy { v };

}*/

/*Exercise 3
int main() {
  std::cout << "\t\t--- creating sink and source ----" << std::endl;
  Tracer sink {"sink"}, source {"source"};

  std::cout << "\t\t--- assigning source to sink ----" << std::endl;
  sink = source;

  std::cout << "\t\t--- showing sink ----" << std::endl;
  sink.show();

  std::cout << "\t\t--- showing source ----" << std::endl;
  source.show();

  std::cout << "\t\t--- end of main ----" << std::endl;
}*/

struct Tracer2 {
  std::string name;

  explicit Tracer2(std::string name = "") : name { name } {
    //std::cout << "Tracer2 created: " << name << std::endl;
  }

  ~Tracer2() {
    //std::cout << "Tracer destroyed: " << name << std::endl;
  }

  Tracer2(Tracer2 const& other) : name { other.name + " copy" } {
    //std::cout << "Tracer copied: " << name << std::endl;
  }
  void show() const {
    //std::cout << "Tracer: " << name << std::endl;
  }


  Tracer2& operator=(Tracer2 const& other) {
	this->name= other.name + " copy";
	return *this;
  }

};

//Exercise 4
int main() {
	  auto start = std::chrono::system_clock::now();
		std::vector<Tracer> v{};
		v.push_back(Tracer{"T1"});
		v.push_back(Tracer{"T2"});
		v.push_back(Tracer{"T3"});
		for (int i = 0; i < 10000000; i++){
			v.push_back(Tracer{"T4"});
		}

		std::vector<Tracer> const v_copy { std::vector<Tracer> { std::move(v) } };
	  std::chrono::duration<double> delta = std::chrono::system_clock::now() - start;
	  std::cout << "creating the container took: " << delta.count() << "s time\n";

	  auto start2 = std::chrono::system_clock::now();
	  		std::vector<Tracer2> v2{};
	  		v2.push_back(Tracer2{"T1"});
	  		v2.push_back(Tracer2{"T2"});
	  		v2.push_back(Tracer2{"T3"});
	  		v2.push_back(Tracer2{"T4"});
	  		for (int i = 0; i < 10000000; i++){
	  			v2.push_back(Tracer2{"T4"});
	  		}

	  		std::vector<Tracer2> const v_copy2 { std::vector<Tracer2> { std::move(v2) } };
	  	  std::chrono::duration<double> delta2 = std::chrono::system_clock::now() - start2;
	  	  std::cout << "creating the container took: " << delta2.count() << "s time\n";
}
