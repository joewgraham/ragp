def run()
    h.run()
    plt.plot(v)
    plt.plot(np.linspace(0,h.tstop,len(v), v))
    plt.plot(t,v)
    plt.show()


    

