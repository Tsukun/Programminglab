using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using Excel = Microsoft.Office.Interop.Excel;
namespace teorverlab1
{
    public partial class Form1 : Form
    {
        static double Generation()
        {
            Random rand = new Random();
            Thread.Sleep(10);
            return rand.NextDouble();
        }
        static double GenerationNormal(double du, double mu, double x)
        {
            return (1 / (du * Math.Sqrt(2 * Math.PI))) * Math.Pow(Math.E, (-Math.Pow(x - mu, 2)) / (2 * du * du));
        }
        static double Aprox(double du, double mu, double k, int interval)
        {
            Random rand = new Random();
            double[] F = new double[interval];
            double[] len = new double[interval];
            double[] P = new double[interval];
            double r1;
            double r2 = 0.0f;
            double step;
            double lboard;
            lboard = mu - k * du;
            step = ((mu + k * du) - (mu - k * du)) / interval;
            len[0] = lboard + step / 2;

            for (int i = 1; i < interval; i++)
            {
                len[i] = len[i - 1] + step;

            }
            for (int i = 0; i < interval; i++)
            {
                F[i] = GenerationNormal(du, mu, len[i]);
                F[interval - i - 1] = F[i];
            }
            for (int i = 0; i < interval; i++)
            {
                P[i] = F[i] / F.Sum();
            }

            len[0] = P[0];
            for (int i = 1; i < interval - 1; i++)
            {
                len[i] = len[i - 1] + P[i];
            }
            len[interval - 1] = 1;


            r1 = Generation();
            if (r1 < len[0])
            {

                r2 = lboard + rand.NextDouble() * step;
                return r2;
            }
            for (int i = 1; i < interval; i++)
            {


                if ((r1 > len[i - 1]) && (r1 <= len[i]))
                {

                    r2 = lboard + step * (i) + rand.NextDouble() * step;

                    return r2;
                }

            }
            return r2;
        }

        void Gist(double mu, double du, double k, int N, int interval, double[] mass)
        {
            double[] arr = new double[interval];
            int sum;
            double xi=0.0f;
            double ni, x = 0;
            double lboard = mu - k * du;
            double[] interv = new double[interval+1];
            double[] Ptheor = new double[interval];
            double[] Pemp = new double[interval];
            double delta = double.Parse(textBox7.Text);
            double step = ((mu + k * du) - (mu - k * du)) / interval;
            for (int i = 0; i < interval; i++)
            {
                for (int b = 0; b < N; b++)
                {
                    if ((mass[b] > lboard + step * (i)) && (mass[b] < lboard + step * (i + 1)))
                        arr[i]++;
                }
                chart1.Series[0].Points.AddXY(i, arr[i]);
            }
            for (int i = 0; i <= interval; i++)
            {
                interv[i] = lboard+step*i;
            }

            for (int i = 0; i < interval; i++)
            {
                for (double j = interv[i]; j < interv[i+1]-delta; j += delta)
                {
                    Ptheor[i] += delta * 0.5f*(GenerationNormal(du, mu, j) + GenerationNormal(du, mu, j + delta));
                }
                Pemp[i] = arr[i] / N;
                xi += (Math.Pow(Ptheor[i] - Pemp[i], 2.0f)) / Ptheor[i];
                
            }
            textBox8.Text = xi.ToString();
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            double du, mu, k;
            int N, interval;
            string s = "";
            N = int.Parse(textBox4.Text);
            interval = int.Parse(textBox5.Text);
            mu = double.Parse(textBox1.Text);
            du = double.Parse(textBox2.Text);
            k = double.Parse(textBox3.Text);
            double[] mass = new double[N];
            double[] norm = new double[N];

            for (int i = 0; i < N; i++)
            {
                mass[i] = Aprox(du, mu, k, interval);
            };

            for (int i = 0; i < N; i++)
            {
                s += mass[i].ToString() + " ";
            }
            textBox6.Text = s;
            chart1.Series[0].Points.Clear();
            Gist(mu, du, k, N, interval, mass);
        }

    
        private void Form1_Load(object sender, EventArgs e)
        {

        }

    }
}