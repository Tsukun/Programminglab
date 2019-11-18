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

namespace teorverlab1
{
    public partial class Form1 : Form
    {
        static double Generation()
        {
            Random rand = new Random();
            Thread.Sleep(100);
            return rand.Next();
        }
        static double GenerationNormal(double du, double mu)
        {
            Random rand = new Random();
            Thread.Sleep(100);
            return (1 / (du * Math.Sqrt(2 * Math.PI))) * Math.Pow(Math.E, (-Math.Pow(rand.NextDouble() - du, 2)) / (2 * du * du));
        }
        static double[] Aprox(double du, double mu, double k, int N, int interval)
        {
            double[] P = new double[interval];
            double[] f = new double[interval];
            double r1;
            double r2;
            double step;
            double lboard;

            lboard = mu - k * du;
            step = ((mu + k * du) - (mu - k * du)) / interval;

            f[0] = lboard + step / 2;
            for (int i = 1; i < interval; i++)
            {
                f[i] = f[i - 1] + step;
            }
            for (int i = 0; i < interval; i++)
            {
                P[i] = f[i] / f.Sum();
            }


            r1 = Generation();
            for (int i = 0; i < N; i++)
            {


                if (r1 < P[i])
                {
                    r2 = Generation();


                }
                else
                    r1 -= P[i];
            }
            return P;
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

            mass = Aprox(du, mu, k, N, interval);

            for (int i = 0; i < interval; i++)
            {
                //chart1.Series[0].Points.AddY(mass[i])
                s += mass[i].ToString() + " "; ;
            }
            textBox6.Text = s;
        }
    }
}