#include <iostream>
#include <iterator>

int puzzle_input[] = {1782, 1344, 1974, 1874, 1800, 1973, 1416, 1952, 1982, 1506, 1642, 1514, 1978, 1895, 1747, 1564, 1398, 1683, 1886, 1492, 1629, 1433, 295 , 1793, 1740, 1852, 1697, 1471, 1361, 1751, 1426, 2004, 1763, 1663, 1742, 1666, 1733, 1880, 1600, 1723, 1478, 1912, 1820, 1615, 1875, 1547, 1554, 752 , 1905, 1368, 954 , 1425, 1391, 691 , 1835, 744 , 1850, 1713, 1995, 1926, 1817, 1774, 1986, 2010, 1427, 1609, 1927, 1362, 1420, 1722, 1590, 1925, 1617, 1434, 1826, 1636, 1687, 1946, 704 , 1797, 1517, 1801, 1865, 1963, 1828, 1829, 1955, 1832, 1987, 1585, 1646, 1575, 1351, 1345, 1729, 1933, 1918, 1902, 1490, 1627, 1370, 1650, 1340, 1539, 1588, 1715, 1573, 1384, 1403, 1673, 1750, 1578, 1831, 1849, 1719, 1359, 2008, 1837, 1958, 480 , 1388, 1770, 1999, 1066, 1730, 1541, 1802, 1962, 1891, 1816, 1505, 1665, 1551, 1954, 1378, 1998, 1612, 1544, 1953, 1502, 1888, 1655, 1614, 1903, 1675, 1498, 1653, 1769, 1863, 1607, 1945, 1651, 1558, 1777, 1460, 1711, 1677, 1988, 1441, 1821, 1867, 1656, 1731, 1885, 1482, 1439, 1990, 1809, 1794, 1951, 1858, 1969, 509 , 1486, 1971, 1557, 1896, 1884, 1834, 1814, 1216, 1997, 1966, 1808, 1754, 1804, 1684, 2001, 1699, 1781, 1429, 1322, 1603, 1596, 1823, 1700, 1552, 1352, 1621, 1669};

int main(int argc, char *argv[])
{
  int puzzle_input_size = std::distance(std::begin(puzzle_input), std::end(puzzle_input));
  std::cout << "SIZE: " << puzzle_input_size << std::endl;
  std::cout << "====" << std::endl;

  long result;
  for ( int i = 0; i < puzzle_input_size - 1; i++ ) {
    for ( int j = i + 1; j < puzzle_input_size; j++ ) {
      result = puzzle_input[i] + puzzle_input[j];
      if (result == 2020) {
        std::cout << "Part one :: " << i << ", " << j << " :: ";
        std::cout << puzzle_input[i] << " + " << puzzle_input[j];
        std::cout << " = " << result << " :: ";
        std::cout << puzzle_input[i] << " * " << puzzle_input[j] << std::endl;
        std::cout << "Part one = " << (puzzle_input[i] * puzzle_input[j]) << std::endl;
        std::cout << "----" << std::endl;
      }
      for (int k = j + 1; k < puzzle_input_size; k++) {
        result = puzzle_input[i] + puzzle_input[j] + puzzle_input[k];
        if (result == 2020) {
          std::cout << "Part two :: " << i << ", " << j << ", " << k << " :: ";
          std::cout << puzzle_input[i] << " + " << puzzle_input[j] << " + " << puzzle_input[k];
          std::cout << " = " << result << " :: ";
          std::cout << puzzle_input[i] << " * " << puzzle_input[j] << " * " << puzzle_input[k] << std::endl;
          std::cout << "Part two = " << (puzzle_input[i] * puzzle_input[j] * puzzle_input[k]) << std::endl;
          std::cout << "----" << std::endl;
        }
      }
    }
  }
  return 0;
}
