using System;
using System.Text.RegularExpressions;
using System.IO;
using System.Xml;
using System.Collections.Generic;


namespace RegExpLab
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = " фыидо, fjbld33- 2олт?";
            Console.WriteLine(str);

            //Regex re = new Regex(@"."); //a) все буквы объект Regex с регулярным выражением @"."
            //Regex re = new Regex(@"\w+"); //b) все слова
            //Regex re = new Regex(@"\b[0-9]+\w+\b"); //c) с цифры
            //Regex re = new Regex(@"\b\w*\d\w*\b"); //d) хотя бы одна цифра
            //Regex re = new Regex(@"\w+3\b"); //e) закагчивающиеся на 3
            //Regex re = new Regex(@"(\w)\1"); //f) повторяющиеся символы
            //Regex re = new Regex(@"\b\w*(\w)\1\w*\b"); //g) все слова со сдвоенными символами
            /*Regex re = new Regex(@"(\W*)(\w+)(\W+)(\w+)(\W+)(\w+)(\W*)");
            Console.WriteLine(re.Replace(Console.ReadLine(), "$1$4$3$2$5$6$7"));*/ //h) $1, $2 ... перестановка слов местами
            //Regex re = new Regex(@"\b[a-zA-Z0-9]+\b"); //i) слова только с латинскими буквами и цифрами
            Regex re = new Regex(@"\b\w*[a-zA-Z]\w*\b");//j) слова, содержащие хотя бы одну латинский буквы
            MatchCollection mc = re.Matches(str);//ищет все совпадения регулярного выражения в строке
            foreach (var m in mc)
                Console.WriteLine(m);
            string orig;
            try
            {
                using (StreamReader sr = new StreamReader("Dictionary.xml"))
                {
                    orig = sr.ReadToEnd();//теперь в строке orig находится полный текст файла
                    Console.WriteLine(orig.Length);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка чтения файла: {ex.Message}");
                return;
            }
            string regulForPustieFormatText = @"<(\w+)>\s*[^\p{L}\p{N}]*\s*</\1>";
            string transformed = Regex.Replace(orig, regulForPustieFormatText, "");
            Console.WriteLine("Найденные пустые теги форматирования:");
            foreach (Match match in Regex.Matches(orig, regulForPustieFormatText))
            {
                Console.WriteLine(match.Value);
            }

            string regulForPustieFormatText2 = @"<(\w+)>\s*[^\p{L}\p{N}]*\s*</\1>";
            // сохраняем в список для последующего анализа
            List<string> doubtfulCases = new List<string>();
            foreach (Match match in Regex.Matches(orig, regulForPustieFormatText2))
            {
                int start = Math.Max(0, match.Index - 20);
                int end = Math.Min(orig.Length - 1, match.Index + match.Length + 20);
                string context = orig.Substring(start, end - start + 1);
                doubtfulCases.Add(context);
            }

            string regulUdaliriLishnieProbeliPeredZnakamiPrepinania = @"\s+([.,;:?!\-\—])";
            transformed = Regex.Replace(transformed, regulUdaliriLishnieProbeliPeredZnakamiPrepinania, "$1"); //удаление пробелов перед знаками препинания
            // проверка изменений
            Console.WriteLine("Случаи с лишними пробелами перед знаками препинания:");
            foreach (Match match in Regex.Matches(transformed, regulUdaliriLishnieProbeliPeredZnakamiPrepinania))
            {
                int start = Math.Max(0, match.Index - 15);// сиволы вокруг найденного совпвдения регулярного выраж 15 до и послк совпадения 
                int end = Math.Min(transformed.Length - 1, match.Index + 15);
                string context = transformed.Substring(start, end - start + 1);
                Console.WriteLine(context);
            }
            string outputPath = "FixedDictionary.xml";
            try
            {
                using (StreamWriter sw = new StreamWriter(outputPath))
                {
                    sw.Write(transformed);
                }
                Console.WriteLine($"Файл сохранён: {outputPath}");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка при записи файла: {ex.Message}");
            }

            XmlDocument doc = new XmlDocument();
            doc.LoadXml(transformed);
        }
    }
}
