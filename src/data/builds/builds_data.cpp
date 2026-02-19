#include <builds_data.hpp>

using namespace std;

const vector<BuildData> BUILDS = {
    BuildData(
        0,
        "Bit manual",
        "Manipulação manual de bits. Lento, primitivo e surpreendentemente satisfatório.",
        1ULL << 3,     // 2^3  = 8 custo inicial mínimo
        1ULL << 0      // 2^0  = 1 produção base
    ),

    BuildData(
        1,
        "Byte organizado",
        "Bits começam a se agrupar. A computação ganha estrutura.",
        1ULL << 6,     // 2^6  = 64
        1ULL << 1      // 2^1  = 2
    ),

    BuildData(
        2,
        "Registrador primitivo",
        "Pequenas memórias internas aceleram operações básicas.",
        1ULL << 9,     // 2^9  = 512
        1ULL << 2      // 2^2  = 4
    ),

    BuildData(
        3,
        "ALU discreta",
        "Uma unidade aritmética rudimentar automatiza cálculos repetitivos.",
        1ULL << 12,    // 2^12 = 4.096
        1ULL << 3      // 2^3  = 8
    ),

    BuildData(
        4,
        "Microprocessador",
        "Integração de lógica em um único chip. O salto começa aqui.",
        1ULL << 15,    // 2^15 = 32.768
        1ULL << 4      // 2^4  = 16
    ),

    BuildData(
        5,
        "Computador pessoal",
        "Processamento acessível e contínuo. A produtividade explode.",
        1ULL << 18,    // 2^18 = 262.144
        1ULL << 6      // 2^6  = 64
    ),

    BuildData(
        6,
        "Servidor dedicado",
        "Máquinas operando sem descanso. Confiáveis e incansáveis.",
        1ULL << 21,    // 2^21 = 2.097.152
        1ULL << 8      // 2^8  = 256
    ),

    BuildData(
        7,
        "Data center modular",
        "Racks de processamento coordenados em larga escala.",
        1ULL << 24,    // 2^24 = 16.777.216
        1ULL << 10     // 2^10 = 1.024
    ),

    BuildData(
        8,
        "Cluster distribuído",
        "Processamento paralelo massivo. Uma mente formada por muitas.",
        1ULL << 28,    // 2^28 = 268.435.456
        1ULL << 12     // 2^12 = 4.096
    ),

    BuildData(
        9,
        "Supercomputador",
        "Capaz de resolver problemas antes considerados impossíveis.",
        1ULL << 32,    // 2^32 aproximadamente 4 bilhões
        1ULL << 16     // 2^16 = 65.536
    ),

    BuildData(
        10,
        "Nuvem global",
        "Processamento invisível e onipresente ao redor do planeta.",
        1ULL << 36,    // 2^36 aproximadamente 68 bilhões
        1ULL << 20     // 2^20 aproximadamente 1 milhão
    ),

    BuildData(
        11,
        "IA autonôma",
        "Sistemas que aprendem, otimizam e evoluem sem intervenção.",
        1ULL << 40,    // 2^40 aproximadamente 1 trilhão
        1ULL << 24     // 2^24 aproximadamente 16 milhões
    ),

    BuildData(
        12,
        "AGI experimental",
        "Inteligência geral emergente. Limites entre código e consciência se confundem.",
        1ULL << 45,    // 2^45 aproximadamente 35 trilhões
        1ULL << 27     // 2^27 aproximadamente 134 milhões
    ),

    BuildData(
        13,
        "Matriz de singularidade",
        "Autoaperfeiçoamento recursivo além da compreensão humana.",
        1ULL << 50,    // 2^50 aproximadamente 1 quadrilhão
        1ULL << 30     // 2^30 aproximadamente 1 bilhão
    ),

    BuildData(
        14,
        "Computador quântico estável",
        "Estados sobrepostos resolvendo bilhões de possibilidades simultaneamente.",
        1ULL << 55,    // 2^55 aproximadamente 36 quadrilhões
        1ULL << 33     // 2^33 aproximadamente 8 bilhões
    ),

    BuildData(
        15,
        "Núcleo quântico infinito",
        "Processamento sem limites aparentes. A computação transcende a realidade.",
        1ULL << 60,    // 2^60 aproximadamente 1 quintilhão
        1ULL << 36     // 2^36 aproximadamente 68 bilhões
    ),
};