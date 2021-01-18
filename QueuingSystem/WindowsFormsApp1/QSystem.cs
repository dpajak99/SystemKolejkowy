using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Math;


namespace WindowsFormsApp1
{
    public partial class QSystem : Form
    {

        public class QueuingSystem
        {
            
            public double lambda, my, c1, c2;
            public int m;
            public double rho, averageV, averageTf, averageN, averageTs, averageMnz, p0;
            


        public static int factorial(int k) {
                int j = 1;
                for (int i = 1; i < k; i++)
                {
                    j *= i;
                }
                return j;
            }

            public double calcAverageV() {
                double numeral = (Math.Pow(rho, (m + 1)) / Math.Pow((m - rho), 2) * factorial(m - 1));
                double sum = 0;
                for (int i = 0; i <= (m - 1); i++)
                {
                    sum += Math.Pow(rho, i) / factorial(i);
                }
                double nominative = sum + (Math.Pow(rho, m) / (factorial(m - 1) * (m - rho)));
                double result = numeral / nominative;

                return result;
            }

            public double getProbability(int j) {
                if (j == 0)
                {
                    double nominal = m - rho;
                    double sum = 0;
                    for (int i = 0; i <= (m - 1); i++)
                    {
                        sum += (m - i) * Math.Pow(rho, i) / factorial(i);
                    }
                    double result = nominal / sum;
                    return result;
                }
                else if (j >= 1 && j <= m)
                {
                    return Math.Pow(rho, j) / factorial(j) * p0;
                }
                return 0.0;
            }

            public static bool isMCorrect(int _m) {
                if (_m >= 1)
                {
                    return true;
                }
                return false;
            }

            static bool isLambdaCorrect(double _lambda, int _m, double _my) {
                if (_lambda < (_m * _my) && ((_lambda / _my) / _m) < 1)
                {
                    return true;
                }
                return false;
            }

            public double calcRho() {
                return lambda / my;
            }
            public double calcAverageTf()
            {
                return averageV / lambda;
            }
            public double calcAverageN()
            {
                return averageV + rho;
            }
            public double calcAverageTs()
            {
                return averageN / lambda;
            }
            public double calcAverageMnz()
            {
                return m - rho;
            }

            public double getLambda()
            {
                return lambda;
            }
            public double getMy()
            {
                return my;
            }
            public int getM()
            {
                return m;
            }
            public double getC1()
            {
                return c1;
            }
            public double getC2()
            {
                return c2;
            }
            public double getAverageV()
            {
                return averageV;
            }
            public double getAverageMnz()
            {
                return averageMnz;
            }

        };

        public QSystem()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }


        private void button1_Click(object sender, EventArgs e)
        {
            QueuingSystem q1 = new QueuingSystem();
            try
            {
                q1.lambda = Convert.ToDouble(textBox7.Text);
                q1.my = Convert.ToDouble(textBox9.Text);
                q1.c1 = Convert.ToDouble(textBox10.Text);
                q1.c2 = Convert.ToDouble(textBox11.Text);
                q1.m = Int32.Parse(textBox8.Text);
                eee.Text = "";
            }
            catch (System.FormatException exception)
            {
                eee.Text = "Bledne dane wejsciowe";
            }

            q1.rho = q1.calcRho();
            q1.averageV = q1.calcAverageV();
            q1.averageTf = q1.calcAverageTf();
            q1.averageN = q1.calcAverageN();
            q1.averageTs = q1.calcAverageTs();
            q1.averageMnz = q1.calcAverageMnz();
            q1.p0 = q1.getProbability(0);

            textBox1.Text = q1.rho.ToString("0.00");
            textBox2.Text = q1.averageV.ToString("0.00");
            textBox3.Text = q1.averageTf.ToString("0.00");
            textBox4.Text = q1.averageN.ToString("0.00");
            textBox6.Text = q1.averageTs.ToString("0.00");
            textBox12.Text = q1.averageMnz.ToString("0.00");
            textBox13.Text = q1.c1.ToString("0.00") + " * " + q1.averageV.ToString("0.00") + " + " + q1.c2.ToString("0.00") + " * " + q1.averageMnz.ToString("0.00");
            textBox5.Text = q1.p0.ToString("0.00");
            textBox14.Text = q1.getProbability(1).ToString("0.00");

        }



        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void textBox7_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void textBox10_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox11_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox9_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox12_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox13_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox14_TextChanged(object sender, EventArgs e)
        {

        }

        private void eee_Click(object sender, EventArgs e)
        {

        }
    }
}
