#include "./effects_data.hpp"
#include <vector>

using namespace std;

const vector<EffectData> EFFECTS = {
    // Multiplicadores por construção (2x permanente)
    EffectData(
        0,
        EffectType::MULTIPLIER,
        EffectTarget::BUILD,
        0,
        "Dedo de Gatilho Binário",
        "Agora seus bits correm mais que elétrons!",
        200,
        Effect::INFINITY
    ),
    EffectData(
        1,
        EffectType::MULTIPLIER,
        EffectTarget::BUILD,
        1,
        "Faxina no CamelCase",
        "Mais organizado que seus arquivos na pasta Downloads.",
        200,
        Effect::INFINITY
    ),
    EffectData(
        2,
        EffectType::MULTIPLIER,
        EffectTarget::BUILD,
        2,
        "Puxadinho de Cache",
        "Memória pequena, mas corre como se fosse grande!",
        200,
        Effect::INFINITY
    ),
    EffectData(
        3,
        EffectType::MULTIPLIER,
        EffectTarget::BUILD,
        3,
        "Calculadora de Padaria 2.0",
        "Faz contas tão rápido que você nem percebe.",
        200,
        Effect::INFINITY
    ),
    EffectData(
        4,
        EffectType::MULTIPLIER,
        EffectTarget::BUILD,
        4,
        "Silício com Cafeína",
        "Integra lógica, café e rock'n'roll em um chip.",
        200,
        Effect::INFINITY
    ),
    EffectData(
        5,
        EffectType::MULTIPLIER,
        EffectTarget::BUILD,
        5,
        "Fim do 'Não Responde'",
        "Finalmente seus programas abrem antes do café esfriar.",
        200,
        Effect::INFINITY
    ),
    EffectData(
        6,
        EffectType::MULTIPLIER,
        EffectTarget::BUILD,
        6,
        "Uptime de Milênio",
        "Pode rodar várias coisas ao mesmo tempo sem surtar.",
        200,
        Effect::INFINITY
    ),
    EffectData(
        7,
        EffectType::MULTIPLIER,
        EffectTarget::BUILD,
        7,
        "Lego de Rack",
        "Mais modular que seu armário de cabos.",
        200,
        Effect::INFINITY
    ),
    EffectData(
        8,
        EffectType::MULTIPLIER,
        EffectTarget::BUILD,
        8,
        "Mente de Enxame Lagada",
        "Muitos computadores unidos, mas continuam fofinhos.",
        200,
        Effect::INFINITY
    ),
    EffectData(
        9,
        EffectType::MULTIPLIER,
        EffectTarget::BUILD,
        9,
        "Deep Blue Jr.",
        "Calcula mais rápido do que sua mente consegue imaginar.",
        200,
        Effect::INFINITY
    ),
    EffectData(
        10,
        EffectType::MULTIPLIER,
        EffectTarget::BUILD,
        10,
        "Cumulus de Dados",
        "Todos os dados estão na nuvem, inclusive suas piadas.",
        200,
        Effect::INFINITY
    ),
    EffectData(
        11,
        EffectType::MULTIPLIER,
        EffectTarget::BUILD,
        11,
        "Skynet Minimalista",
        "Produz bits sozinha, sem café ou procrastinação.",
        200,
        Effect::INFINITY
    ),
    EffectData(
        12,
        EffectType::MULTIPLIER,
        EffectTarget::BUILD,
        12,
        "Filósofo de Terminal",
        "Quase pensante, mas ainda ama loops infinitos.",
        200,
        Effect::INFINITY
    ),
    EffectData(
        13,
        EffectType::MULTIPLIER,
        EffectTarget::BUILD,
        13,
        "Event Horizon Digital",
        "Onde os bits entram e a realidade sai confusa.",
        200,
        Effect::INFINITY
    ),
    EffectData(
        14,
        EffectType::MULTIPLIER,
        EffectTarget::BUILD,
        14,
        "Gato de Schrödinger Vivo",
        "Apenas tente não olhar para ele enquanto calcula.",
        200,
        Effect::INFINITY
    ),
    EffectData(
        15,
        EffectType::MULTIPLIER,
        EffectTarget::BUILD,
        15,
        "Buffer Infinito",
        "Pode conter todos os bits do universo, inclusive os imaginários.",
        200,
        Effect::INFINITY
    ),

    // Multiplicadores globais 2x permanente
    EffectData(
        16,
        EffectType::MULTIPLIER,
        EffectTarget::GLOBAL_PRODUCTION,
        -1,
        "Cafeína no Mainframe",
        "Todo mundo produz em dobro, ninguém reclama!",
        200,
        Effect::INFINITY
    ),
    EffectData(
        17,
        EffectType::MULTIPLIER,
        EffectTarget::GLOBAL_PRODUCTION,
        -1,
        "Internet das Torradeiras",
        "Agora até a torradeira do vizinho entra no loop.",
        200,
        Effect::INFINITY
    ),
    EffectData(
        18,
        EffectType::MULTIPLIER,
        EffectTarget::GLOBAL_PRODUCTION,
        -1,
        "Decreto 404: Eficiência",
        "A ONU aprova multiplicadores de bits.",
        200,
        Effect::INFINITY
    ),
    EffectData(
        19,
        EffectType::MULTIPLIER,
        EffectTarget::GLOBAL_PRODUCTION,
        -1,
        "Superposição Lucrativa",
        "Todos os bits agora existem em múltiplas realidades.",
        200,
        Effect::INFINITY
    ),
    EffectData(
        20,
        EffectType::MULTIPLIER,
        EffectTarget::GLOBAL_PRODUCTION,
        -1,
        "Ctrl+C Ctrl+V Universal",
        "Produção infinita? Talvez... cuidado com paradoxos!",
        200,
        Effect::INFINITY
    )
};