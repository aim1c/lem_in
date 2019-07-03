# lem_in

В начале из стандартного вывода программа получает информацию о количестве муравьев, которые должны были быть приведены через путь, имена комнат (могут быть числами, словами, символами) С координатами и ссылками.
Далее она обрабатывает эту информацию и ищет путь (если муравьев будет выгоднее пускать по нескольким путям или развилкам, то алгоритм это сделает) для всех муравьев с минимальными действиями для них (действие = строка)

Запуск:

make
./lem-in_gen [количество муравьев] [количество комнат (узлов в графе)] > map

./lem_in < map
