import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import CP_GrScaleTestFrame;

//==============================================================================
// Hauptklasse f�r Applet CP_GrScaleTest
//
//==============================================================================
public class CP_GrScaleTest extends Applet
{
	private int i = 0;
	private int q = 0;

	private double m_scalePadding = 0.1;
	
	private CP_GrScale[] scales = new CP_GrScale[4];

	// UNTERST�TZUNG F�R EINZELPLATZANWENDUNGEN:
	//		m_fStandAlone wird auf true gesetzt, falls das Applet eigenst�ndig ausgef�hrt wird
	//--------------------------------------------------------------------------
	private boolean m_fStandAlone = false;

	// UNTERST�TZUNG F�R EINZELPLATZANWENDUNGEN
	// 	Die Methode main() stellt den Einsprungpunkt des Applets dar, wenn es als eigenst�ndige
	// Anwendung ausgef�hrt wird. Diese wird ignoriert, falls das Applet innerhalb
	// einer HTML-Seite ausgef�hrt wird.
	//--------------------------------------------------------------------------
	public static void main(String args[])
	{
		// Erstellen sie ein Fenster auf der obersten Ebene, das das Applet CP_GrScaleTest enth�lt
		//----------------------------------------------------------------------
		CP_GrScaleTestFrame frame = new CP_GrScaleTestFrame("CP_GrScaleTest");

		// Rahmen (Frame) muss vor dem Dimensionieren angezeigt werden, damit insets() g�ltige Werte zur�ckgibt
		//----------------------------------------------------------------------
		frame.show();
        frame.setVisible(true);
		frame.setSize(frame.insets().left + frame.insets().right  + 320,
					  frame.insets().top  + frame.insets().bottom + 240);

		// Der folgende Code startet die Ausf�hrung des Applets innerhalb des Rahmenfensters.
		// Hier wird auch GetParameters() aufgerufen, um die Parameterwerte der
		// Befehlszeile abzurufen, und m_fStandAlone auf true gesetzt, um zu verhindern,
		// dass init() diese Werte aus der HTML-Seite holt.
		//----------------------------------------------------------------------
		CP_GrScaleTest applet_CP_GrScaleTest = new CP_GrScaleTest();

		frame.add("Center", applet_CP_GrScaleTest);
		applet_CP_GrScaleTest.m_fStandAlone = true;
		applet_CP_GrScaleTest.init();
		applet_CP_GrScaleTest.start();
        frame.show();
	}

	// CP_GrScaleTest Klassen-Konstruktor
	//--------------------------------------------------------------------------
	public CP_GrScaleTest()
	{
		// ZU ERLEDIGEN: Platzieren Sie hier Code f�r den Konstruktor
	}

	// APPLET-INFO-UNTERST�TZUNG:
	//		Die Methode getAppletInfo() gibt eine Zeichenfolge zur�ck, die Autor/Autorin,
	// Copyright-Datum oder verschiedene andere Informationen des Applets beschreibt
    //--------------------------------------------------------------------------
	public String getAppletInfo()
	{
		return "Name: CP_GrScaleTest\r\n" +
		       "Autor/Autorin: Unbekannt\r\n" +
		       "Erstellt mit Microsoft Visual J++ Version 1.1";
	}


	//Die Methode init() wird vom AWT aufgerufen, wenn ein Applet erstmals geladen oder
	//neu geladen wird. �berschreiben Sie diese Methode, um jede Initialisierung auszuf�hren,
	//die das Applet ben�tigt (z. B. die Initialisierung von Datenstrukturen, das Laden von Bildern oder
	//Schriftarten, das Erstellen von Rahmenfenstern, das Festlegen des Layout-Managers oder das Hinzuf�gen von
	//Komponenten der Benutzeroberfl�che).
    //--------------------------------------------------------------------------
	public void init()
	{
        //Wenn Sie eine mit Hilfe des Ressourcen-Assistenten generierte Steuerelement-Erstellungklasse verwenden,
        //um die Steuerelemente in Ihrem Applet anzuordnen, k�nnen Sie dessen Methode
        //CreateControls() von dieser Methode aus aufrufen. Entfernen Sie dazu den folgenden
        //Aufruf von resize(), bevor Sie den Aufruf von CreateControls() einf�gen.
        //CreateControls() f�hrt eine eigene Gr��en�nderung durch.
        //----------------------------------------------------------------------
    	resize(320, 240);

		// ZU ERLEDIGEN: Platzieren Sie hier zus�tzlichen Code f�r die Initialisierung 
	}

	// Hier zus�tzlichen Bereinigungscode f�r das Applet platzieren. destroy() wird aufgerufen, 
	// wenn das Applet beendet und entladen wird
	//-------------------------------------------------------------------------
	public void destroy()
	{
		// ZU ERLEDIGEN: Platzieren Sie hier Bereinigungscode f�r das Applet 
	}

	// CP_GrScaleTest Zeichnungsbehandlungsroutine
	//--------------------------------------------------------------------------
/*	public void paint(Graphics g)
	{
		g.drawString("Erstellt mit Microsoft Visual J++ Version 1.1", 10, 20);
	}
*/
	//		Die Methode start() wird aufgerufen, wenn die Seite, die das Applet enth�lt,
	// erstmals auf dem Bildschirm erscheint. Die Startimplementierung des Applet-Assistenten
	// dieser Methode startet die Ausf�hrung des Threads des Applets.
	//--------------------------------------------------------------------------
	public void start()
	{
		/*_CPDEBUG_BEGIN
		final CP_Debug debug = new CP_Debug("ATCMControl Console Debug");
		CP_GrScale.m_debug = debug;
		CP_GrScalePainter.m_debug = debug;
		CP_GrScaleModel.m_debug = debug;
		_CPDEBUG_END*/

		final Color[] bg = { 
			new Color(0x100000 * 0x6),
			new Color(0x001000 * 0x6),
			new Color(0x000010 * 0x6),
			new Color(0x101000 * 0x6)
		};
		final Color[] fg = {
			new Color(0xff0000),
			new Color(0x00f000),
			new Color(0x9090ff),
			new Color(0xf0f000)
		};

		final double[] minVals = new double[6];
		final double[] maxVals = new double[6];
		minVals[0] = -1.234;
		maxVals[0] = 1.567;
		minVals[1] = 0;
		maxVals[1] = 1;
		minVals[2] = 0;
		maxVals[2] = 100;
		minVals[3] = 0;
		maxVals[3] = 1000000000;
		minVals[4] = 2345;
		maxVals[4] = 1000008453;
		minVals[5] = -1000008453;
		maxVals[5] = -2345;
		
		int maxIndex = 5;

		final double min =  minVals[i];
		final double max =  maxVals[i];


		GridBagLayout gridBag = new GridBagLayout();
		GridBagConstraints c = new GridBagConstraints();
		setLayout(gridBag);

		Panel scales = createScalePanel(min, max, minVals, maxVals, fg, bg);
		Panel controls = createControlPanel(min, max, minVals, maxVals);

		c.gridwidth = GridBagConstraints.REMAINDER;
		c.fill = GridBagConstraints.BOTH;
		c.weightx = 1.0;
		c.weighty = 1.0;
		gridBag.setConstraints(scales, c);
		add(scales);

		c.gridwidth = GridBagConstraints.REMAINDER;
		c.fill = GridBagConstraints.BOTH;
		c.weightx = 1.0;
		c.weighty = 0.0;
		gridBag.setConstraints(controls, c);
		add(controls);
	}
	
	public Panel createScalePanel(
		double min,
		double max,
		final double[] minVals,
		final double[] maxVals,
		Color[] fg,
		Color[] bg
		)
	{
		Panel cont = new Panel();
		cont.setBackground(Color.black);

		GridBagLayout gridBag = new GridBagLayout();
		GridBagConstraints c = new GridBagConstraints();		
		
		cont.setLayout(gridBag);

		Panel left = new Panel();
		GridLayout leftL = new GridLayout(1,1);
		left.setLayout(leftL);
		CP_GrScaleV verScaleRight = new CP_GrScaleV(
			min, max, 0, true, m_scalePadding);
		left.add(verScaleRight);
		verScaleRight.setBackground(bg[0]);
		verScaleRight.setForeground(fg[0]);
		c.fill = GridBagConstraints.BOTH;    
		c.weightx = 1.0;
		c.weighty = 1.0;
		c.gridwidth = 2;
		c.gridheight = 1;
		gridBag.setConstraints(left, c);
		cont.add(left);
		

		Panel mid = new Panel();
		mid.setLayout(new GridLayout(2,1));
		CP_GrScaleH horScaleDown = new CP_GrScaleH(
			min, max, 0, true, m_scalePadding);
		horScaleDown.setBackground(bg[1]);
		horScaleDown.setForeground(fg[1]);
		mid.add(horScaleDown);
		
		CP_GrScaleH horScaleUp = new CP_GrScaleH(
			min, max, 0, false, m_scalePadding);
		horScaleUp.setBackground(bg[2]);
		horScaleUp.setForeground(fg[2]);
		mid.add(horScaleUp);
		
		c.fill = GridBagConstraints.BOTH;    
		c.weightx = 1.0;
		c.weighty = 1.0;
		c.gridwidth = 1;
		c.gridheight = 1;
		gridBag.setConstraints(mid, c);
		cont.add(mid);
		
		Panel right = new Panel();
		right.setLayout(new GridLayout(1,1));
		CP_GrScaleV verScaleLeft = new CP_GrScaleV(
			min, max, 0, false, m_scalePadding);
		right.add(verScaleLeft);
		verScaleLeft.setBackground(bg[3]);
		verScaleLeft.setForeground(fg[3]);
		c.fill = GridBagConstraints.BOTH;    
		c.weightx = 1.0;
		c.weighty = 1.0;
		c.gridwidth = GridBagConstraints.REMAINDER;
		c.gridheight = 1;
		gridBag.setConstraints(right, c);
		cont.add(right);
		
		scales[0] = verScaleRight;
		scales[1] = horScaleDown;
		scales[2] = horScaleUp;
		scales[3] = verScaleLeft;
		
		return cont;
	}

	public Panel createControlPanel(
		double min,
		double max,
		final double[] minVals,
		final double[] maxVals
		)
	{
		Panel control = new Panel();
		control.setLayout(new GridLayout(2,5));

		final TextField minField = new TextField(String.valueOf(min), 16);
		minField.setEditable(false);
		control.add(minField);

		final TextField maxField = new TextField(String.valueOf(max), 16);
		maxField.setEditable(false);
		control.add(maxField);

		Button bNext = new Button("Next");
		control.add(bNext);
		class NextActionListener implements ActionListener
		{
			public void actionPerformed(ActionEvent e)
			{
				i = (i+1) % minVals.length;
				setScales(minVals[i], maxVals[i]);
				minField.setText(String.valueOf(minVals[i]));
				maxField.setText(String.valueOf(maxVals[i]));
			}
		}
		bNext.addActionListener(new NextActionListener());

		Button bToggleQ = new Button("Toggle Quality");;
		control.add(bToggleQ);
		class ToggleQActionListener implements ActionListener
		{
			public void actionPerformed(ActionEvent e)
			{
				toggleQualities();
			}
		}
		bToggleQ.addActionListener(new ToggleQActionListener());

		Button shrink= new Button("Shrink");;
		control.add(shrink);
		class ShrinkActionListener implements ActionListener
		{
			public void actionPerformed(ActionEvent e)
			{
				m_scalePadding += 0.01;
				for(int i = 0; i < scales.length; i++)
				{
					scales[i].setPadding(m_scalePadding);
				}
			}
	
		};
		shrink.addActionListener(new ShrinkActionListener());

		Button grow= new Button("Grow");;
		control.add(grow);
		class GrowActionListener implements ActionListener
		{
			public void actionPerformed(ActionEvent e)
			{
				m_scalePadding -= 0.01;
				for(int i = 0; i < scales.length; i++)
				{
					scales[i].setPadding(m_scalePadding);
				}
			}
	
		};
		grow.addActionListener(new GrowActionListener());
		
		return control;
	}

	public void setScales(double min, double max)
	{
		for(int j = 0; j < scales.length; j++)
		{
			scales[j].setDomain(min, max);
		}

	}

	public void toggleQualities()
	{
		q = (q+1) % 2;
		for(int j = 0; j < scales.length; j++)
		{
			scales[j].setQuality(q);
		}
	}

	//		Die Methode stop() wird aufgerufen, wenn die Seite, die das Applet enth�lt,
	// nicht mehr auf dem Bildschirm angezeigt wird. Die Startimplementierung des Applet-Assistenten
	// dieser Methode beendet die Ausf�hrung des Threads des Applets.
	//--------------------------------------------------------------------------
	public void stop()
	{
	}

	// ZU ERLEDIGEN:  F�gen Sie hier den zus�tzlichen Applet-Code ein

}
