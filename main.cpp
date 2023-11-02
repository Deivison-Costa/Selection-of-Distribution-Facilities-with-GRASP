#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <locale>

using namespace std;

// estrutura Cidade
struct Cidade {
    string nome;
    double latitude;
    double longitude;
};

// função para calcular a distância entre duas coordenadas geográficas.
// complexidade de tempo: O(1)
double dist(double lat1, double lon1, double lat2, double lon2) {
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    // fórmula de haversine
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return 6371 * c;
}

// algoritmo GRASP
// complexidade de tempo: O(maxIter * numInstalacoes * cidades.size() * numInstalacoes)
// complexidade de espaço: O(cidades.size())
string grasp(vector<Cidade>& cidades, int numInstalacoes) {
    const int maxIter = 1000;

    vector<int> melhoresSolucoes(numInstalacoes, 0);  // armazena as melhores soluções encontradas.
    double menorCusto = numeric_limits<double>::max();  // armazena o menor custo entre as soluções.

    for (int i = 0; i < maxIter; i++) { // loop principal que executa o GRASP maxIter vezes.
        vector<int> solucaoAtual(numInstalacoes, 0); // representa a solução atual.
        double custoAtual = 0.0;  // armazena o custo da solução atual.

        for (int j = 0; j < numInstalacoes; j++) { // loop para escolher aleatoriamente locais de instalação.
            int indiceAleatorio = rand() % cidades.size(); // escolhe um índice aleatório.
            solucaoAtual[j] = indiceAleatorio; // armazena o índice na solução atual.
        }

        for (int j = 0; j < cidades.size(); j++) { // loop para calcular o custo da solução atual.
            double minDist = numeric_limits<double>::max(); // inicializa a distância mínima com um valor grande.
            for (int k = 0; k < numInstalacoes; k++) {
                double d = dist(cidades[j].latitude, cidades[j].longitude, cidades[solucaoAtual[k]].latitude, cidades[solucaoAtual[k]].longitude);
                if (d < minDist) {
                    minDist = d; // atualiza a distância mínima se uma mais curta for encontrada.
                }
            }
            custoAtual += minDist; // acumula a distância mínima no custo total da solução atual.
        }

        if (custoAtual < menorCusto) {
            menorCusto = custoAtual; // atualiza o menor custo encontrado até agora.
            melhoresSolucoes = solucaoAtual; // armazena a solução como a melhor solução.
        }
    }

    string resultado = "Cidades selecionadas para instalações: ";
    for (int i = 0; i < numInstalacoes; i++) {
        resultado += "\n" + cidades[melhoresSolucoes[i]].nome; // string do resultado com as cidades escolhidas.
    }

    return resultado;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(0)); 

    vector<Cidade> cidades = {
        {"Cidade 1", 40.7128, -74.0060},
        {"Cidade 2", 34.0522, -118.2437},
        {"Cidade 3", 41.8781, -87.6298},
        {"Cidade 4", 51.5074, -0.1278},
        {"Cidade 5", 48.8566, 2.3522},
        {"Cidade 6", 55.7558, 37.6176},
        {"Cidade 7", 35.682839, 139.759455},
        {"Cidade 8", 37.7749, -122.4194},
        {"Cidade 9", 19.4326, -99.1332},
        {"Cidade 10", 52.5200, 13.4050},
        {"Cidade 11", 43.6532, -79.3832},
        {"Cidade 12", 34.0522, -118.2437},
        {"Cidade 13", 51.5074, -0.1278},
        {"Cidade 14", 48.8566, 2.3522},
        {"Cidade 15", 55.7558, 37.6176},
        {"Cidade 16", 35.682839, 139.759455},
        {"Cidade 17", 37.7749, -122.4194},
        {"Cidade 18", 19.4326, -99.1332},
        {"Cidade 19", 52.5200, 13.4050},
        {"Cidade 20", 43.6532, -79.3832},
        {"Cidade 21", 41.8781, -87.6298},
        {"Cidade 22", 51.5074, -0.1278},
        {"Cidade 23", 48.8566, 2.3522},
        {"Cidade 24", 55.7558, 37.6176},
        {"Cidade 25", 35.682839, 139.759455},
        {"Cidade 26", 37.7749, -122.4194},
        {"Cidade 27", 19.4326, -99.1332},
        {"Cidade 28", 52.5200, 13.4050},
        {"Cidade 29", 43.6532, -79.3832},
        {"Cidade 30", 34.0522, -118.2437},
        {"Cidade 31", 41.8781, -87.6298},
        {"Cidade 32", 51.5074, -0.1278},
        {"Cidade 33", 48.8566, 2.3522},
        {"Cidade 34", 55.7558, 37.6176},
        {"Cidade 35", 35.682839, 139.759455},
        {"Cidade 36", 37.7749, -122.4194},
        {"Cidade 37", 19.4326, -99.1332},
        {"Cidade 38", 52.5200, 13.4050},
        {"Cidade 39", 43.6532, -79.3832},
        {"Cidade 40", 40.7128, -74.0060},
        {"Cidade 41", 34.0522, -118.2437},
        {"Cidade 42", 41.8781, -87.6298},
        {"Cidade 43", 51.5074, -0.1278},
        {"Cidade 44", 48.8566, 2.3522},
        {"Cidade 45", 55.7558, 37.6176},
        {"Cidade 46", 35.682839, 139.759455},
        {"Cidade 47", 37.7749, -122.4194},
        {"Cidade 48", 19.4326, -99.1332},
        {"Cidade 49", 52.5200, 13.4050},
        {"Cidade 50", 43.6532, -79.3832},
        {"Cidade 51", 34.0522, -118.2437},
        {"Cidade 52", 41.8781, -87.6298},
        {"Cidade 53", 51.5074, -0.1278},
        {"Cidade 54", 48.8566, 2.3522},
        {"Cidade 55", 55.7558, 37.6176},
        {"Cidade 56", 35.682839, 139.759455},
        {"Cidade 57", 37.7749, -122.4194},
        {"Cidade 58", 19.4326, -99.1332},
        {"Cidade 59", 52.5200, 13.4050},
        {"Cidade 60", 43.6532, -79.3832},
        {"Cidade 61", 40.7128, -74.0060},
        {"Cidade 62", 34.0522, -118.2437},
        {"Cidade 63", 41.8781, -87.6298},
        {"Cidade 64", 51.5074, -0.1278},
        {"Cidade 65", 48.8566, 2.3522},
        {"Cidade 66", 55.7558, 37.6176},
        {"Cidade 67", 35.682839, 139.759455},
        {"Cidade 68", 37.7749, -122.4194},
        {"Cidade 69", 19.4326, -99.1332},
        {"Cidade 70", 52.5200, 13.4050},
        {"Cidade 71", 43.6532, -79.3832},
        {"Cidade 72", 34.0522, -118.2437},
        {"Cidade 73", 41.8781, -87.6298},
        {"Cidade 74", 51.5074, -0.1278},
        {"Cidade 75", 48.8566, 2.3522},
        {"Cidade 76", 55.7558, 37.6176},
        {"Cidade 77", 35.682839, 139.759455},
        {"Cidade 78", 37.7749, -122.4194},
        {"Cidade 79", 19.4326, -99.1332},
        {"Cidade 80", 52.5200, 13.4050},
        {"Cidade 81", 43.6532, -79.3832},
        {"Cidade 82", 40.7128, -74.0060},
        {"Cidade 83", 34.0522, -118.2437},
        {"Cidade 84", 41.8781, -87.6298},
        {"Cidade 85", 51.5074, -0.1278},
        {"Cidade 86", 48.8566, 2.3522},
        {"Cidade 87", 55.7558, 37.6176},
        {"Cidade 88", 35.682839, 139.759455},
        {"Cidade 89", 37.7749, -122.4194},
        {"Cidade 90", 19.4326, -99.1332},
        {"Cidade 91", 52.5200, 13.4050},
        {"Cidade 92", 43.6532, -79.3832},
        {"Cidade 93", 40.7128, -74.0060},
        {"Cidade 94", 34.0522, -118.2437},
        {"Cidade 95", 41.8781, -87.6298},
        {"Cidade 96", 51.5074, -0.1278},
        {"Cidade 97", 48.8566, 2.3522},
        {"Cidade 98", 55.7558, 37.6176},
        {"Cidade 99", 35.682839, 139.759455},
        {"Cidade 100", 37.7749, -122.4194}
    };

    int numInstalacoes = 4; // nº de instalações a serem selecionadas.
    string solucao = grasp(cidades, numInstalacoes); // aplica GRASP e mostra a solução
    cout << solucao << endl;

    return 0;
}
