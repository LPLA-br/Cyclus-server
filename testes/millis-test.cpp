//testando Mock de millis

#include <chrono>
#include <cstdio>

auto inicio = std::chrono::high_resolution_clock::now();

int millis()
{
  auto agora = std::chrono::high_resolution_clock::now();
  auto intervalo = std::chrono::duration_cast<std::chrono::milliseconds>(agora - inicio);
  return (intervalo.count());
}

int main()
{
  printf("um segundo contado por millis\n");
  printf("tempo inicial, %i\n", millis());
  while ( true )
  {
    if ( millis() == 1000 ) break;
  }
  printf("tempo final:%i\n", millis());
}
